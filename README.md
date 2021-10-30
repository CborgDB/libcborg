# libcborg

This library is developed for the [CborgDB project](https://github.com/cborgdb/cborg).

## Build and Install

```sh
$ git clone https://github.com/cborgdb/libcborg.git
$ cd libcborg
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make test
$ sudo make install
```

## Uninstall

```sh
$ sudo make uninstall
```

## Usage and build

- Bitset

```sh
$ gcc bitset_example.c -o bitset_example -lcborg
$ ./bitset_example
bs: 1111011111
bs_string: 1111011111
```

```C
#include <stdio.h>
#include <cborg/ds/bitset.h>

int main() {
  // bitset : 0000000000
  bitset_t *bs = cb_ds_bitset_new(10);

  // return 0
  cb_ds_bitset_count(bs);

  // return 10
  cb_ds_bitset_size(bs);

  // bitset: 1000000000
  cb_ds_bitset_set(bs, 0, true);
  
  // return true
  cb_ds_bitset_test(bs,0);

  // return false
  cb_ds_bitset_test(bs,1);

  // return true because bs have bit set 
  cb_ds_bitset_any(bs);

  // return false because bs have bit set
  cb_ds_bitset_none(bs);

  // return false 
  cb_ds_bitset_all(bs);
  
  // bitset: 0111111111
  cb_ds_bitset_flip(bs);

  // bitset: 0000000000
  cb_ds_bitset_reset(bs);
  
  // bitset: 1111111111
  cb_ds_bitset_flip(bs);

  // bitset: 1111011111
  cb_ds_bitset_set(bs, 4, false);

  // write bitset to file
  cb_ds_bitset_write(bs, "./bitset.bs");

  // read bitset from file
  bitset_t *bs_read = cb_ds_bitset_read("./bitset.bs");

  char *bs_string = cb_ds_bitset_to_string(bs);
  char *bs_read_string = cb_ds_bitset_to_string(bs_read);
  
  // printf
  // bs: 1111011111
  // bs_read: 1111011111
  printf("bs: %s\n",bs_string);
  printf("bs_read: %s\n",bs_read_string);

  // free
  free(bs_string);
  cb_ds_bitset_delete(bs);
  free(bs_read_string);
  cb_ds_bitset_delete(bs_read);
  return 0;
}

```

- Bloom

```sh
$ gcc bloom_example.c -o bloom_example -lcborg
$ ./bloom_example
```

```C
#include <stdio.h>
#include <cborg/ds/bloom.h>
#include <cborg/hash.h>

int main() {
  bloom_filter_t *b1 = cb_ds_bloom_new(cb_hash_fnv1a, cb_hash_murmur2_64a, 1000);
  cb_ds_bloom_insert(b1, "hello", 6);
  cb_ds_bloom_insert(b1, "hello world!", 12);
  cb_ds_bloom_delete(&b1);
  return 0;
}

```

- Btree [TODO]

```sh
$ gcc btree_example.c -o btree_example -lcborg
$ ./btree_example
```

```C
#include <stdio.h>
#include <cborg/ds/btree.h>

int main() {
  return 0;
}

```

- Hash

```sh
$ gcc hash_example.c -o hash_example -lcborg
$ ./hash_example
11900548196712136313
9114364940175044080
8796868307739761162
```

```C
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <cborg/hash.h>

int main() {
  char *data = "hashme";
  // fnv1a
  uint64_t hfnv = cb_hash_fnv1a(data, 7);
  printf("%"PRIu64"\n",hfnv);

  // city
  uint64_t hc64 = cb_hash_city64(data, 7);
  printf("%"PRIu64"\n",hc64);

  // murmur2_64a
  uint64_t hm64 = cb_hash_murmur2_64a(data, 7);
  printf("%"PRIu64"\n",hm64);

  return 0;
}

```
- Endianness

```sh
$ gcc endianness_example.c -o endianness_example -lcborg
$ ./endianness_example
is_little_endian = 1
8961
1732584193
17279655951921914625
```

```C
#include <stdio.h>
#include <inttypes.h>
#include <cborg/os/endianness.h>

int main() {
  printf("cb_is_little_endian = %d\n", cb_is_little_endian());
  printf("%u\n", cb_bswap16(0x0123));
  printf("%u\n", cb_bswap32(0x01234567u));
  printf("%"PRIu64"\n", cb_bswap64(0x0123456789ABCDEFllu));
  return 0;
}

```

## License

???