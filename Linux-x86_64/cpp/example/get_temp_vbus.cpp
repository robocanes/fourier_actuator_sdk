#include "fsav2.h"

#include <cstdio>
#include <ctime>

#define NANOSEC_PER_SEC (1000000000) // 10^9
static uint64_t
get_mono_timestamp_ns(void) {
#ifdef __linux__
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
  return (uint64_t)ts.tv_sec * NANOSEC_PER_SEC + ts.tv_nsec;
#elif defined(_WIN32)
// TODO: Windows
#endif
}

using namespace AC2;

int
main() {
  FSA         fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::YIELD_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  FSA::temp_vbus_t rx_temp_vbus{};

  while (true) {
    uint64_t start = get_mono_timestamp_ns();

    ret = fsa.GetTempVbus(rx_temp_vbus);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get Temp and Vbus failed with code: %d\n", ip, static_cast<int>(ret));

    uint64_t end = get_mono_timestamp_ns();

    printf("FSA(%s): elapsed time: %ld us\n", ip, (end - start) / 1000);

    printf("FSA(%s): mos_temp: %.4lf, coil_temp: %.4lf, vbus: %.4lf\n",
           ip,
           rx_temp_vbus.mos,
           rx_temp_vbus.coil,
           rx_temp_vbus.vbus);
  }

  return 0;
}