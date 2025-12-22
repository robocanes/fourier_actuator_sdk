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

  FSA::err_code_t rx_error{};

  while (true) {
    auto start = std::chrono::steady_clock::now();

    ret = fsa.GetErrCode(rx_error);
    if (ret != FSA::ret_e::SUCCESS)
      printf("FSA(%s): Get Error failed with code: %d\n", ip,
             static_cast<int>(ret));

    auto end = std::chrono::steady_clock::now();

    printf("FSA(%s): elapsed time: %ld us\n", ip,
           std::chrono::duration_cast<std::chrono::microseconds>(end - start)
               .count());

    for (int i = 0; i < 8; i++)
      printf("FSA(%s): Error%d: %#x\n", ip, i, rx_error.arr[i]);
  }

  return 0;
}
