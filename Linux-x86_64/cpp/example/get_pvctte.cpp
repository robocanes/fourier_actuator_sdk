#include "fsav2.h"

#include <chrono>
#include <cstdio>

using namespace AC2;

int main() {
  FSA fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::SPIN_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  FSA::pvctte_t rx_pvctte{};

  while (true) {
    auto start = std::chrono::steady_clock::now();

    ret = fsa.GetPVCTTe(rx_pvctte);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get PVCTTe failed with code: %d\n", ip,
             static_cast<int>(ret));

    auto end = std::chrono::steady_clock::now();

    printf("FSA(%s): elapsed time: %ld us\n", ip,
           std::chrono::duration_cast<std::chrono::microseconds>(end - start)
               .count());

    printf("FSA(%s): pos: %.4lf, vel: %.4lf, cur: %.4lf, tor: %.4lf, tor_e: "
           "%.4lf\n",
           ip, rx_pvctte.pos, rx_pvctte.vel, rx_pvctte.cur, rx_pvctte.tor,
           rx_pvctte.tor_e);
  }

  return 0;
}
