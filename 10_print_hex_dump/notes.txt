void print_hex_dump(const char *level, const char *prefix_str, int prefix_type, int rowsize, int groupsize, const void *buf, size_t len, bool ascii);

Given a buffer print_hex_dump prints a hex + ASCII dump to the kernel log at the specified kernel log level, with an optional leading prefix.

level:
        kernel log level (e.g. KERN_DEBUG)

prefix_str:
        string to prefix each line with;

prefix_type:
        controls whether prefix of an offset, address, or none
        is printed (%DUMP_PREFIX_OFFSET, \ ``DUMP_PREFIX_ADDRESS``\ , \ ``DUMP_PREFIX_NONE``\ )

rowsize:
        number of bytes to print per line; must be 16 or 32

groupsize:
        number of bytes to print at a time (1, 2, 4, 8; default = 1)

buf:
        data blob to dump

len:
        number of bytes in buf

ascii:
        include ASCII after the hex output
