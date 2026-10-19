/*
 * static_key_disable() for kernels that do not provide it.
 *
 * SukiSU's adb_root / selinux_hide / shell_su_adb_only features call it to
 * turn their fast path off. MuMu's 6.1.90 kernel is built without
 * CONFIG_JUMP_LABEL, so the symbol is never emitted and the module cannot
 * resolve it; those features then simply stay enabled, which is the state the
 * module is in before any feature is toggled.
 */
#include <linux/static_key.h>

#ifndef CONFIG_JUMP_LABEL
void static_key_disable(struct static_key *key)
{
	(void)key;
}
#endif
