/*
 * Stub for a symbol the target kernel does not export.
 *
 * SukiSU's adb_root / selinux_hide / shell_su_adb_only features call
 * static_key_disable() to turn their fast path off. MuMu's 6.1.90 kernel is
 * built without CONFIG_JUMP_LABEL, so static_key_disable() is not emitted and
 * the module cannot resolve it. Without it those three features simply stay
 * enabled, which is the same behaviour the module has before any feature is
 * toggled.
 *
 * Declared weak so a kernel that does export the real symbol wins.
 */
#include <linux/static_key.h>

void __weak static_key_disable(struct static_key *key)
{
	(void)key;
}
