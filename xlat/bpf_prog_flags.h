/* Generated by ./xlat/gen.sh from ./xlat/bpf_prog_flags.in; do not edit. */
#if !(defined(BPF_F_STRICT_ALIGNMENT) || (defined(HAVE_DECL_BPF_F_STRICT_ALIGNMENT) && HAVE_DECL_BPF_F_STRICT_ALIGNMENT))
# define BPF_F_STRICT_ALIGNMENT 1
#endif

#ifdef IN_MPERS

# error static const struct xlat bpf_prog_flags in mpers mode

#else

static
const struct xlat bpf_prog_flags[] = {
 XLAT(BPF_F_STRICT_ALIGNMENT),
 XLAT_END
};

#endif /* !IN_MPERS */