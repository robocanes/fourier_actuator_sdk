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

  FSA::err_code_t rx_error{};

  while (true) {
    uint64_t start = get_mono_timestamp_ns();

    ret = fsa.GetErrCode(rx_error);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get Error failed with code: %d\n", ip, static_cast<int>(ret));

    uint64_t end = get_mono_timestamp_ns();

    printf("FSA(%s): elapsed time: %ld us\n", ip, (end - start) / 1000);

    for (int i = 0; i < 8; i++)
      printf("FSA(%s): Error%d: %#x\n", ip, i, rx_error.arr[i]);
  }

  return 0;
}