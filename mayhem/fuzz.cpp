#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    int src_width = provider.ConsumeIntegralInRange<int>(0, INT_MAX);
    int src_height = provider.ConsumeIntegralInRange<int>(0, INT_MAX);
    int dest_width_inout = provider.ConsumeIntegral<int>();
    int dest_height_inout = provider.ConsumeIntegral<int>();
    int font_ratio = provider.ConsumeFloatingPointInRange<float>(1, 100);
    int zoom = provider.ConsumeIntegral<int>();
    int stretch = provider.ConsumeIntegral<int>();

    // chafa_calc_canvas_geometry(src_width, src_height, &dest_width_inout, &dest_height_inout, font_ratio, zoom, stretch);

    return 0;
}