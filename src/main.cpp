// SPDX-License-Identifier:  MIT
// Copyright(C) 2019-2023 Profs. Said Hanafi & Igor Coelho

#include <string>
#include <vector>
//
#include <Scanner++/Scanner.hpp>

using namespace scannerpp;  // NOLINT

struct SUKP {
  int m;                             // number of items
  int n;                             // number of elements
  int ne;                            // number of edges
  int b;                             // knapsack capacity
  std::vector<int> c;                // cost per item
  std::vector<int> a;                // weight per element
  std::vector<std::vector<int>> A;   // matrix m x n
  std::vector<std::vector<int>> Ni;  // matrix m x n
  std::vector<std::vector<int>> Mj;  // matrix n x m
  std::vector<int> ni;  // sz: m number of elements per item
  std::vector<int> mj;  // sz: n
  int last_i{-1};       // for debug purposes
  int last_j{-1};       // for debug purposes

  double alpha;  // 0.1 or 0.15
  double beta;   // 0.75 or 0.85

  void summary() {
    std::cout << "Summary: m=" << m << " n=" << n
              << " ne=" << ne << " b=" << b << std::endl;
    // Make sure you read all data
    std::cout << "Debug: last_i=" << last_i
              << " last_j=" << last_j << std::endl;
  }
};

SUKP loadSUKP(std::string instance) {
  Scanner scanner{File{instance}};

  SUKP problem;
  problem.m = *scanner.nextInt();
  problem.n = *scanner.nextInt();
  problem.ne = *scanner.nextInt();
  problem.b = *scanner.nextInt();
  std::cout << "reading c for m items" << std::endl;
  problem.c = std::vector<int>(problem.m, 0);
  for (int i = 0; i < problem.m; i++)
    problem.c[i] = *scanner.nextInt();
  std::cout << "reading a for n elements" << std::endl;
  problem.a = std::vector<int>(problem.n, 0);
  for (int j = 0; j < problem.n; j++)
    problem.a[j] = *scanner.nextInt();
  problem.ni = std::vector<int>(problem.m, 0);
  problem.A = std::vector<std::vector<int>>(
      problem.m, std::vector<int>(problem.n, 0));
  problem.mj = std::vector<int>(problem.n, 0);
  problem.Ni = std::vector<std::vector<int>>(
      problem.m, std::vector<int>(problem.n, 0));
  problem.Mj = std::vector<std::vector<int>>(
      problem.n, std::vector<int>(problem.m, 0));

  for (int k = 0; k < problem.ne; k++) {
    int i = *scanner.nextInt();
    int j = *scanner.nextInt();
    problem.last_i = i;
    problem.last_j = j;
    problem.A[i][j] = 1;
    problem.Ni[i][problem.ni[i]] = j;
    problem.ni[i]++;
    problem.Mj[j][problem.mj[j]] = i;
    problem.mj[j]++;
  }
  return problem;
}

int main() {
  auto sukp = loadSUKP(
      "SUKP_He_al_generated/sukp01_85_100_0.10_0.75.txt");
  sukp.summary();
  return 0;
}
