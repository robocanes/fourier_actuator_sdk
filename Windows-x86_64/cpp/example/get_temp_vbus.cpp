#include "fsav2.h"

#include <chrono>
#include <cstdio>

using namespace AC2;

int main() {
  FSA fsa;
  const char *ip = "192.168.137.101";

  FSA::ret_e ret = fsa.Init(ip, FSA::net_recv_mode_e::YIELD_WAIT);
  if (ret != FSA::ret_e::SUCCESS) {
    printf("FSA(%s): init failed with code: %d\n", ip, static_cast<int>(ret));
    return -1;
  }

  FSA::temp_vbus_t rx_temp_vbus{};

  while (true) {
    auto start = std::chrono::steady_clock::now();

    ret = fsa.GetTempVbus(rx_temp_vbus);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get Temp and Vbus failed with code: %d\n", ip,
             static_cast<int>(ret));

    auto end = std::chrono::steady_clock::now();

    printf("FSA(%s): elapsed time: %ld us\n", ip,
           std::chrono::duration_cast<std::chrono::microseconds>(end - start)
               .count());

    printf("FSA(%s): mos_temp: %.4lf, coil_temp: %.4lf, vbus: %.4lf\n", ip,
           rx_temp_vbus.mos, rx_temp_vbus.coil, rx_temp_vbus.vbus);
  }

  return 0;
}
