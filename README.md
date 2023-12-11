## instances-sukp

Public instances for the Set-Union Knapsack Problem (SUKP).

Data is on folder [SUKP_He_al_generated](./SUKP_He_al_generated/README.txt).

Data reader is on `src` and uses Scanner++ library in `include/` folder.

Expected output:

```
int main() {
  auto sukp = loadSUKP("SUKP_He_al_generated/sukp01_85_100_0.10_0.75.txt");
  sukp.summary();
  // reading c for m items
  // reading a for n elements
  // Summary: m=85 n=100 ne=812 b=12180
  // Debug: last_i=84 last_j=99
  return 0;
}
```

## License

MIT License
Copyleft 2019-2023
