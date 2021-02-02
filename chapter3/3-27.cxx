int func() { return 42; }

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
  unsigned int kBufSize = 1024;
  int ia[kBufSize];
  // NOTE: Disabling linting as assignment ask for variable-length arrays
  int ib[4 * 7 - 14];  // NOLINT
  int ic[func()];      // NOLINT
  // char st[11] = "fundamental";  // Missing null character
#pragma clang diagnostic pop
  return 0;
}
