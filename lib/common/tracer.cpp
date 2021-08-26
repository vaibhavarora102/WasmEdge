#include "common/tracer.h"

namespace WasmEdge {
namespace Tracer
{
void initTracer()
{
  auto exporter = std::unique_ptr<sdktrace::SpanExporter>(
      new opentelemetry::exporter::trace::OStreamSpanExporter);
  auto processor = std::unique_ptr<sdktrace::SpanProcessor>(
      new sdktrace::SimpleSpanProcessor(std::move(exporter)));
  auto provider = nostd::shared_ptr<opentelemetry::trace::TracerProvider>(
      new sdktrace::TracerProvider(std::move(processor)));

  // Set the global trace provider
  opentelemetry::trace::Provider::SetTracerProvider(provider);
}


nostd::shared_ptr<trace::Tracer> get_tracer()
{
  auto provider = trace::Provider::GetTracerProvider();
  return provider->GetTracer("wasmedge-tracer");
}

}  // namespace Tracer
}  // namespace WasmEdge