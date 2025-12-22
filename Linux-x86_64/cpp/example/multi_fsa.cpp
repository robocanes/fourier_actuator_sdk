#include "fsav2.h"

#include <chrono>
#include <cstdio>

#include <thread>
#include <vector>

using namespace AC2;

#define FSA_NUM 7

int main() {
  FSA fsas[FSA_NUM];
  const char *ip[FSA_NUM] = {
      "192.168.137.101", "192.168.137.101", "192.168.137.101",
      "192.168.137.101", "192.168.137.101", "192.168.137.101",
      "192.168.137.101",
  };

  for (size_t i = 0; i < FSA_NUM; i++) {
    FSA::ret_e ret = fsas[i].Init(ip[i], FSA::net_recv_mode_e::YIELD_WAIT);
    if (ret != FSA::ret_e::SUCCESS) {
      printf("FSA(%s): init failed with code: %d\n", ip[i],
             static_cast<int>(ret));
      return -1;
    }
  }

  std::vector<std::thread> threads;
  for (size_t i = 0; i < FSA_NUM; i++) {
    threads.emplace_back([&, i]() {
      FSA::pvctte_t rx_pvctte{};
      while (true) {
        auto start = std::chrono::steady_clock::now();

        FSA::ret_e ret = fsas[i].GetPVCTTe(rx_pvctte);
        if (ret != FSA::ret_e::SUCCESS) {
          printf("FSA(%s): GetPVCTTe failed with code: %d\n", ip[i],
                 static_cast<int>(ret));
        }

        auto end = std::chrono::steady_clock::now();

        printf(
            "FSA(%s): elapsed time: %ld us\n", ip[i],
            std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                .count());

        printf("FSA(%s): pos: %.4lf, vel: %.4lf, cur: %.4lf, tor: %.4lf, "
               "tor_e: %.4lf\n",
               ip[i], rx_pvctte.pos, rx_pvctte.vel, rx_pvctte.cur,
               rx_pvctte.tor, rx_pvctte.tor_e);
      }
    });
  }

  for (auto &th : threads) {
    th.join();
  }

  return 0;
}
