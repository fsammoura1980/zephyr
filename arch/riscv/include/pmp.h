/*
 * Copyright (c) 2022 BayLibre, SAS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PMP_H_
#define PMP_H_

void z_riscv_pmp_init(void);
void z_riscv_pmp_stackguard_prepare(struct k_thread *thread);
void z_riscv_pmp_stackguard_enable(struct k_thread *thread);
void z_riscv_pmp_stackguard_disable(void);
void z_riscv_pmp_usermode_init(struct k_thread *thread);
void z_riscv_pmp_usermode_prepare(struct k_thread *thread);
void z_riscv_pmp_usermode_enable(struct k_thread *thread);
void z_riscv_custom_pmp_entry_enable(void);


#ifdef CONFIG_CUSTOM_PMP_ENTRY

/**
 * @brief Sets the write permission for a specific PMP entry.
 *
 * Searches for the PMP entry corresponding to the Device Tree memory
 * region at the given index. Modifies the Write (W) bit in this
 * entry's PMP configuration.
 *
 * @note This function currently supports up to 8 PMP slots (CONFIG_PMP_SLOTS <= 8).
 *
 * @param write_enable If true, enables writes to the region (sets W bit).
 *                     If false, disables writes (clears W bit).
 * @param region_idx The index of the region in the array returned
 *                   by mem_attr_get_regions(), for which to modify PMP settings.
 *
 * @return 0 on success.
 *         -EINVAL if region_idx is out of bounds.
 *         -ENOENT if the matching PMP entry is not found.
 *         -ENOTSUP if CONFIG_PMP_SLOTS > 8.
 */
int riscv_pmp_set_write_permission(bool write_enable, size_t region_idx);

#endif

#endif /* PMP_H_ */
