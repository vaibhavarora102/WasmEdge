#pragma once

#include "opentelemetry/trace/provider.h"
#include "opentelemetry/sdk/trace/simple_processor.h"
#include "opentelemetry/sdk/trace/tracer_provider.h"
#include "opentelemetry/exporters/ostream/span_exporter.h"

namespace trace = opentelemetry::trace;
namespace nostd = opentelemetry::nostd;

namespace WasmEdge {
namespace Tracer {

void initTracer();

nostd::shared_ptr<trace::Tracer> get_tracer();

}  // namespace Tracer
}  // namespace WasmEdge


