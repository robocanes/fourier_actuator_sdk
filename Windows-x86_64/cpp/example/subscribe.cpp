#include "fsav2.h"

#include <unistd.h>

#include <csignal>
#include <cstdint>
#include <cstdio>
#include <ctime>

#define NANOSEC_PER_SEC (1000000000) // 10^9
#define MICROSEC_PER_SEC (1000000)   // 10^6
#define MILLISEC_PER_SEC (1000)      // 10^3
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

volatile sig_atomic_t stop_flag = 0;
void
signal_handler(int sig) {
  if (sig == SIGINT) {
    stop_flag = 1;
    printf("\nReceived SIGINT, terminating...\n");
  }
}

using namespace AC2;

int
main() {
  signal(SIGINT, signal_handler);

  FSA         fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::SPIN_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  FSA::subs_config_t subs_config{
    .enable     = 1,
    .pos        = 1,
    .vel        = 1,
    .cur        = 1,
    .tor        = 1,
    .error      = 1,
    .error_ext2 = 1,
    .error_ext3 = 1,
    .error_ext4 = 1,
    .error_ext5 = 1,
    .error_ext6 = 1,
    .error_ext7 = 1,
    .error_ext8 = 1,
  };

  ret = fsa.EnableSubscribe(subs_config);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): Enable subscribe failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  FSA::subs_data_t subs_data = {};

  uint64_t last_timestamp_ns = 0;

  while (!stop_flag) {
    uint64_t now_timestamp_ns = get_mono_timestamp_ns();
    if (now_timestamp_ns - last_timestamp_ns < 1 * (NANOSEC_PER_SEC / MILLISEC_PER_SEC))
      continue;
    last_timestamp_ns = now_timestamp_ns;

    ret = fsa.GetSubsData(subs_data);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get subscribe data failed with code: %d\n", ip, static_cast<int>(ret));

    printf("FSA(%s): pos: %.4lf, vel: %.4lf, cur: %.4lf, tor: %.4lf, cnt: %d, error: %d, "
           "ext2: %d, ext3: %d, ext4: %d, ext5: %d, ext6: %d, ext7: %d, ext8: %d\n",
           ip,
           subs_data.pvct.pos,
           subs_data.pvct.vel,
           subs_data.pvct.cur,
           subs_data.pvct.tor,
           subs_data.cnt,
           subs_data.error[0],
           subs_data.error[1],
           subs_data.error[2],
           subs_data.error[3],
           subs_data.error[4],
           subs_data.error[5],
           subs_data.error[6],
           subs_data.error[7]);
  }

  subs_config.enable = 0;
  fsa.EnableSubscribe(subs_config);

  return 0;
}