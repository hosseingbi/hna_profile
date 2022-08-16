#ifndef HNA_PROFILE_H
#define HNA_PROFILE_H

#define HNA_PROFILE_MAX_CORES 32
#define HNA_PROFILE_MAX_VAR 64


/** tsc part is copied from DPDK. */
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
#define HNA_STD_C11 __extension__
#else
#define RTE_STD_C11
#endif

static inline uint64_t
hna_rdtsc(void)
{
	union {
		uint64_t tsc_64;
		HNA_STD_C11
		struct {
			uint32_t lo_32;
			uint32_t hi_32;
		};
	} tsc;

	asm volatile("rdtsc" :
		     "=a" (tsc.lo_32),
		     "=d" (tsc.hi_32));
	return tsc.tsc_64;
}

typedef enum {hna_elemtype_timer, hna_elemtype_counter=1} hna_prof_elemtype;

struct hna_prof_elm
{
    hna_prof_elemtype type;
    long long unsigned cnt;
    long long unsigned max_time;
    long long unsigned avg_time;
    long long unsigned start_time;
    long long unsigned current_time;
    long long unsigned sum_time;
    u_int16_t id;
};

#define HNA_PROF_DECLARE_VAR(var) \
            struct hna_prof_elm hna_prof_##var[HNA_PROFILE_MAX_CORES];

#define HNA_PROF_DECLARE_VAR_EXTERN(var) \
            extern struct hna_prof_elm hna_prof_##var[HNA_PROFILE_MAX_CORES];

#define HNA_PROF_DECLARE_ALL_VARS_EXTERN \
            HNA_PROF_DECLARE_VAR_EXTERN(0) \
            HNA_PROF_DECLARE_VAR_EXTERN(1) \
            HNA_PROF_DECLARE_VAR_EXTERN(2) \
            HNA_PROF_DECLARE_VAR_EXTERN(3) \
            HNA_PROF_DECLARE_VAR_EXTERN(4) \
            HNA_PROF_DECLARE_VAR_EXTERN(5) \
            HNA_PROF_DECLARE_VAR_EXTERN(6) \
            HNA_PROF_DECLARE_VAR_EXTERN(7) \
            HNA_PROF_DECLARE_VAR_EXTERN(8) \
            HNA_PROF_DECLARE_VAR_EXTERN(9) \
            HNA_PROF_DECLARE_VAR_EXTERN(10) \
            HNA_PROF_DECLARE_VAR_EXTERN(11) \
            HNA_PROF_DECLARE_VAR_EXTERN(12) \
            HNA_PROF_DECLARE_VAR_EXTERN(13) \
            HNA_PROF_DECLARE_VAR_EXTERN(14) \
            HNA_PROF_DECLARE_VAR_EXTERN(15) \
            HNA_PROF_DECLARE_VAR_EXTERN(16) \
            HNA_PROF_DECLARE_VAR_EXTERN(17) \
            HNA_PROF_DECLARE_VAR_EXTERN(18) \
            HNA_PROF_DECLARE_VAR_EXTERN(19) \
            HNA_PROF_DECLARE_VAR_EXTERN(20) \
            HNA_PROF_DECLARE_VAR_EXTERN(21) \
            HNA_PROF_DECLARE_VAR_EXTERN(22) \
            HNA_PROF_DECLARE_VAR_EXTERN(23) \
            HNA_PROF_DECLARE_VAR_EXTERN(24) \
            HNA_PROF_DECLARE_VAR_EXTERN(25) \
            HNA_PROF_DECLARE_VAR_EXTERN(26) \
            HNA_PROF_DECLARE_VAR_EXTERN(27) \
            HNA_PROF_DECLARE_VAR_EXTERN(28) \
            HNA_PROF_DECLARE_VAR_EXTERN(29) \
            HNA_PROF_DECLARE_VAR_EXTERN(30) \
            HNA_PROF_DECLARE_VAR_EXTERN(31) \
            HNA_PROF_DECLARE_VAR_EXTERN(32) \
            HNA_PROF_DECLARE_VAR_EXTERN(33) \
            HNA_PROF_DECLARE_VAR_EXTERN(34) \
            HNA_PROF_DECLARE_VAR_EXTERN(35) \
            HNA_PROF_DECLARE_VAR_EXTERN(36) \
            HNA_PROF_DECLARE_VAR_EXTERN(37) \
            HNA_PROF_DECLARE_VAR_EXTERN(38) \
            HNA_PROF_DECLARE_VAR_EXTERN(39) \
            HNA_PROF_DECLARE_VAR_EXTERN(40) \
            HNA_PROF_DECLARE_VAR_EXTERN(41) \
            HNA_PROF_DECLARE_VAR_EXTERN(42) \
            HNA_PROF_DECLARE_VAR_EXTERN(43) \
            HNA_PROF_DECLARE_VAR_EXTERN(44) \
            HNA_PROF_DECLARE_VAR_EXTERN(45) \
            HNA_PROF_DECLARE_VAR_EXTERN(46) \
            HNA_PROF_DECLARE_VAR_EXTERN(47) \
            HNA_PROF_DECLARE_VAR_EXTERN(48) \
            HNA_PROF_DECLARE_VAR_EXTERN(49) \
            HNA_PROF_DECLARE_VAR_EXTERN(50) \
            HNA_PROF_DECLARE_VAR_EXTERN(51) \
            HNA_PROF_DECLARE_VAR_EXTERN(52) \
            HNA_PROF_DECLARE_VAR_EXTERN(53) \
            HNA_PROF_DECLARE_VAR_EXTERN(54) \
            HNA_PROF_DECLARE_VAR_EXTERN(55) \
            HNA_PROF_DECLARE_VAR_EXTERN(56) \
            HNA_PROF_DECLARE_VAR_EXTERN(57) \
            HNA_PROF_DECLARE_VAR_EXTERN(58) \
            HNA_PROF_DECLARE_VAR_EXTERN(59) \
            HNA_PROF_DECLARE_VAR_EXTERN(60) \
            HNA_PROF_DECLARE_VAR_EXTERN(61) \
            HNA_PROF_DECLARE_VAR_EXTERN(62) \
            HNA_PROF_DECLARE_VAR_EXTERN(63)


HNA_PROF_DECLARE_ALL_VARS_EXTERN


#define HNA_AVG_PROPORTIONAL(core, prof_id) hna_prof_##prof_id[core].avg_time = (hna_prof_##prof_id[core].avg_time * RTE_MIN(hna_prof_##prof_id[core].cnt, 1000) + hna_prof_##prof_id[core].current_time - hna_prof_##prof_id[core].avg_time)/RTE_MIN(hna_prof_##prof_id[core].cnt, 1000);

#define HNA_AVG_DEFINITE(core, prof_id) hna_prof_##prof_id[core].sum_time += hna_prof_##prof_id[core].current_time; \
            hna_prof_##prof_id[core].avg_time = hna_prof_##prof_id[core].sum_time/hna_prof_##prof_id[core].cnt; 

#define HNA_AVG(core, prof_id) HNA_AVG_DEFINITE(core, prof_id)


#define HNA_PROF_FUNC(func, core, prof_id) \
            hna_prof_##prof_id[core].type = hna_elemtype_timer; \
            hna_prof_##prof_id[core].start_time = hna_rdtsc(); \
            func; \
            hna_prof_##prof_id[core].current_time = hna_rdtsc() - hna_prof_##prof_id[core].start_time; \
            hna_prof_##prof_id[core].cnt++; \
            HNA_AVG(core, prof_id) \
            if( hna_prof_##prof_id[core].max_time < hna_prof_##prof_id[core].current_time) hna_prof_##prof_id[core].max_time = hna_prof_##prof_id[core].current_time;


#define HNA_PROF_START(core, prof_id) \
            hna_prof_##prof_id[core].type = hna_elemtype_timer; \
            hna_prof_##prof_id[core].start_time = hna_rdtsc();


#define HNA_PROF_END(core, prof_id) \
            hna_prof_##prof_id[core].current_time = hna_rdtsc() - hna_prof_##prof_id[core].start_time; \
            hna_prof_##prof_id[core].cnt++; \
            HNA_AVG(core, prof_id) \
            if( hna_prof_##prof_id[core].max_time < hna_prof_##prof_id[core].current_time) hna_prof_##prof_id[core].max_time = hna_prof_##prof_id[core].current_time;



#define HNA_PROF_COUNTER(core, prof_id) \
            hna_prof_##prof_id[core].type = hna_elemtype_counter; \
            hna_prof_##prof_id[core].cnt++;


#ifdef __cplusplus
extern "C"
{
#endif

void hna_profile_show_res();
void hna_profile_init();

#ifdef __cplusplus
}
#endif

#endif // HNA_PROFILE_H