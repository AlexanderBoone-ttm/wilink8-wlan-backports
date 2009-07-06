#ifndef LINUX_26_31_COMPAT_H
#define LINUX_26_31_COMPAT_H

#include <linux/autoconf.h>
#include <linux/version.h>
#include <linux/compat_autoconf.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,31))

#include <linux/skbuff.h>
#include <net/dst.h>
#include <net/genetlink.h>

#ifndef SDIO_DEVICE_ID_MARVELL_8688WLAN
#define SDIO_DEVICE_ID_MARVELL_8688WLAN		0x9104
#endif

#ifndef ERFKILL
#if !defined(CONFIG_ALPHA) && !defined(CONFIG_MIPS) && !defined(CONFIG_PARISC) && !defined(CONFIG_SPARC)
#define ERFKILL		132	/* Operation not possible due to RF-kill */
#endif
#ifdef CONFIG_ALPHA
#define ERFKILL		138	/* Operation not possible due to RF-kill */
#endif
#ifdef CONFIG_MIPS
#define ERFKILL		167	/* Operation not possible due to RF-kill */
#endif
#ifdef CONFIG_PARISC
#define ERFKILL		256	/* Operation not possible due to RF-kill */
#endif
#ifdef CONFIG_SPARC
#define ERFKILL		134	/* Operation not possible due to RF-kill */
#endif
#endif

#ifndef NETDEV_PRE_UP
#define NETDEV_PRE_UP		0x000D
#endif

/*
 * Added via adf30907d63893e4208dfe3f5c88ae12bc2f25d5
 *
 * There is no _sk_dst on older kernels, so just set the
 * old dst to NULL and release it directly.
 */
static inline void skb_dst_drop(struct sk_buff *skb)
{
	dst_release(skb->dst);
	skb->dst = NULL;
}

extern int genl_register_family_with_ops(struct genl_family *family,
	struct genl_ops *ops, size_t n_ops);

#endif /* (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,31)) */

#endif /* LINUX_26_31_COMPAT_H */
