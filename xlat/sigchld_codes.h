/* Generated by ./xlat/gen.sh from ./xlat/sigchld_codes.in; do not edit. */

#include "gcc_compat.h"
#include "static_assert.h"

#if defined(CLD_EXITED) || (defined(HAVE_DECL_CLD_EXITED) && HAVE_DECL_CLD_EXITED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_EXITED) == (1), "CLD_EXITED != 1");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_EXITED 1
#endif
#if defined(CLD_KILLED) || (defined(HAVE_DECL_CLD_KILLED) && HAVE_DECL_CLD_KILLED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_KILLED) == (2), "CLD_KILLED != 2");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_KILLED 2
#endif
#if defined(CLD_DUMPED) || (defined(HAVE_DECL_CLD_DUMPED) && HAVE_DECL_CLD_DUMPED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_DUMPED) == (3), "CLD_DUMPED != 3");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_DUMPED 3
#endif
#if defined(CLD_TRAPPED) || (defined(HAVE_DECL_CLD_TRAPPED) && HAVE_DECL_CLD_TRAPPED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_TRAPPED) == (4), "CLD_TRAPPED != 4");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_TRAPPED 4
#endif
#if defined(CLD_STOPPED) || (defined(HAVE_DECL_CLD_STOPPED) && HAVE_DECL_CLD_STOPPED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_STOPPED) == (5), "CLD_STOPPED != 5");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_STOPPED 5
#endif
#if defined(CLD_CONTINUED) || (defined(HAVE_DECL_CLD_CONTINUED) && HAVE_DECL_CLD_CONTINUED)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((CLD_CONTINUED) == (6), "CLD_CONTINUED != 6");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define CLD_CONTINUED 6
#endif

#ifndef XLAT_MACROS_ONLY

# ifdef IN_MPERS

extern const struct xlat sigchld_codes[];

# else

#  if !(defined HAVE_M32_MPERS || defined HAVE_MX32_MPERS)
static
#  endif
const struct xlat sigchld_codes[] = {
 XLAT(CLD_EXITED),
 XLAT(CLD_KILLED),
 XLAT(CLD_DUMPED),
 XLAT(CLD_TRAPPED),
 XLAT(CLD_STOPPED),
 XLAT(CLD_CONTINUED),
 XLAT_END
};

# endif /* !IN_MPERS */

#endif /* !XLAT_MACROS_ONLY */
