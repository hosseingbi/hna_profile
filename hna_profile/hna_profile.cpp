#include <iostream>
#include <map>
#include <fstream>
#include "hna_profile.h"

std::ofstream fout;

#define HNA_PROF_DECLARE_ALL_VARS \
            HNA_PROF_DECLARE_VAR(0) \
            HNA_PROF_DECLARE_VAR(1) \
            HNA_PROF_DECLARE_VAR(2) \
            HNA_PROF_DECLARE_VAR(3) \
            HNA_PROF_DECLARE_VAR(4) \
            HNA_PROF_DECLARE_VAR(5) \
            HNA_PROF_DECLARE_VAR(6) \
            HNA_PROF_DECLARE_VAR(7) \
            HNA_PROF_DECLARE_VAR(8) \
            HNA_PROF_DECLARE_VAR(9) \
            HNA_PROF_DECLARE_VAR(10) \
            HNA_PROF_DECLARE_VAR(11) \
            HNA_PROF_DECLARE_VAR(12) \
            HNA_PROF_DECLARE_VAR(13) \
            HNA_PROF_DECLARE_VAR(14) \
            HNA_PROF_DECLARE_VAR(15) \
            HNA_PROF_DECLARE_VAR(16) \
            HNA_PROF_DECLARE_VAR(17) \
            HNA_PROF_DECLARE_VAR(18) \
            HNA_PROF_DECLARE_VAR(19) \
            HNA_PROF_DECLARE_VAR(20) \
            HNA_PROF_DECLARE_VAR(21) \
            HNA_PROF_DECLARE_VAR(22) \
            HNA_PROF_DECLARE_VAR(23) \
            HNA_PROF_DECLARE_VAR(24) \
            HNA_PROF_DECLARE_VAR(25) \
            HNA_PROF_DECLARE_VAR(26) \
            HNA_PROF_DECLARE_VAR(27) \
            HNA_PROF_DECLARE_VAR(28) \
            HNA_PROF_DECLARE_VAR(29) \
            HNA_PROF_DECLARE_VAR(30) \
            HNA_PROF_DECLARE_VAR(31) \
            HNA_PROF_DECLARE_VAR(32) \
            HNA_PROF_DECLARE_VAR(33) \
            HNA_PROF_DECLARE_VAR(34) \
            HNA_PROF_DECLARE_VAR(35) \
            HNA_PROF_DECLARE_VAR(36) \
            HNA_PROF_DECLARE_VAR(37) \
            HNA_PROF_DECLARE_VAR(38) \
            HNA_PROF_DECLARE_VAR(39) \
            HNA_PROF_DECLARE_VAR(40) \
            HNA_PROF_DECLARE_VAR(41) \
            HNA_PROF_DECLARE_VAR(42) \
            HNA_PROF_DECLARE_VAR(43) \
            HNA_PROF_DECLARE_VAR(44) \
            HNA_PROF_DECLARE_VAR(45) \
            HNA_PROF_DECLARE_VAR(46) \
            HNA_PROF_DECLARE_VAR(47) \
            HNA_PROF_DECLARE_VAR(48) \
            HNA_PROF_DECLARE_VAR(49) \
            HNA_PROF_DECLARE_VAR(50) \
            HNA_PROF_DECLARE_VAR(51) \
            HNA_PROF_DECLARE_VAR(52) \
            HNA_PROF_DECLARE_VAR(53) \
            HNA_PROF_DECLARE_VAR(54) \
            HNA_PROF_DECLARE_VAR(55) \
            HNA_PROF_DECLARE_VAR(56) \
            HNA_PROF_DECLARE_VAR(57) \
            HNA_PROF_DECLARE_VAR(58) \
            HNA_PROF_DECLARE_VAR(59) \
            HNA_PROF_DECLARE_VAR(60) \
            HNA_PROF_DECLARE_VAR(61) \
            HNA_PROF_DECLARE_VAR(62) \
            HNA_PROF_DECLARE_VAR(63)


#define HNA_PROF_COPY_VAR(prof_elem, core_id, prof_id) \
            prof_elem.cnt = hna_prof_##prof_id[core_id].cnt; \
            prof_elem.max_time = hna_prof_##prof_id[core_id].max_time; \
            prof_elem.avg_time = hna_prof_##prof_id[core_id].avg_time; \
            prof_elem.current_time = hna_prof_##prof_id[core_id].current_time; \
            prof_elem.type = hna_prof_##prof_id[core_id].type; \
            prof_elem.id = prof_id;

#define HNA_PROF_COPY_VAR_ARR(prof_elem_arr, coreid) \
            HNA_PROF_COPY_VAR(prof_elem_arr[0], coreid, 0) \
            HNA_PROF_COPY_VAR(prof_elem_arr[1], coreid, 1) \
            HNA_PROF_COPY_VAR(prof_elem_arr[2], coreid, 2) \
            HNA_PROF_COPY_VAR(prof_elem_arr[3], coreid, 3) \
            HNA_PROF_COPY_VAR(prof_elem_arr[4], coreid, 4) \
            HNA_PROF_COPY_VAR(prof_elem_arr[5], coreid, 5) \
            HNA_PROF_COPY_VAR(prof_elem_arr[6], coreid, 6) \
            HNA_PROF_COPY_VAR(prof_elem_arr[7], coreid, 7) \
            HNA_PROF_COPY_VAR(prof_elem_arr[8], coreid, 8) \
            HNA_PROF_COPY_VAR(prof_elem_arr[9], coreid, 9) \
            HNA_PROF_COPY_VAR(prof_elem_arr[10], coreid, 10) \
            HNA_PROF_COPY_VAR(prof_elem_arr[11], coreid, 11) \
            HNA_PROF_COPY_VAR(prof_elem_arr[12], coreid, 12) \
            HNA_PROF_COPY_VAR(prof_elem_arr[13], coreid, 13) \
            HNA_PROF_COPY_VAR(prof_elem_arr[14], coreid, 14) \
            HNA_PROF_COPY_VAR(prof_elem_arr[15], coreid, 15) \
            HNA_PROF_COPY_VAR(prof_elem_arr[16], coreid, 16) \
            HNA_PROF_COPY_VAR(prof_elem_arr[17], coreid, 17) \
            HNA_PROF_COPY_VAR(prof_elem_arr[18], coreid, 18) \
            HNA_PROF_COPY_VAR(prof_elem_arr[19], coreid, 19) \
            HNA_PROF_COPY_VAR(prof_elem_arr[20], coreid, 20) \
            HNA_PROF_COPY_VAR(prof_elem_arr[21], coreid, 21) \
            HNA_PROF_COPY_VAR(prof_elem_arr[22], coreid, 22) \
            HNA_PROF_COPY_VAR(prof_elem_arr[23], coreid, 23) \
            HNA_PROF_COPY_VAR(prof_elem_arr[24], coreid, 24) \
            HNA_PROF_COPY_VAR(prof_elem_arr[25], coreid, 25) \
            HNA_PROF_COPY_VAR(prof_elem_arr[26], coreid, 26) \
            HNA_PROF_COPY_VAR(prof_elem_arr[27], coreid, 27) \
            HNA_PROF_COPY_VAR(prof_elem_arr[28], coreid, 28) \
            HNA_PROF_COPY_VAR(prof_elem_arr[29], coreid, 29) \
            HNA_PROF_COPY_VAR(prof_elem_arr[30], coreid, 30) \
            HNA_PROF_COPY_VAR(prof_elem_arr[31], coreid, 31) \
            HNA_PROF_COPY_VAR(prof_elem_arr[32], coreid, 32) \
            HNA_PROF_COPY_VAR(prof_elem_arr[33], coreid, 33) \
            HNA_PROF_COPY_VAR(prof_elem_arr[34], coreid, 34) \
            HNA_PROF_COPY_VAR(prof_elem_arr[35], coreid, 35) \
            HNA_PROF_COPY_VAR(prof_elem_arr[36], coreid, 36) \
            HNA_PROF_COPY_VAR(prof_elem_arr[37], coreid, 37) \
            HNA_PROF_COPY_VAR(prof_elem_arr[38], coreid, 38) \
            HNA_PROF_COPY_VAR(prof_elem_arr[39], coreid, 39) \
            HNA_PROF_COPY_VAR(prof_elem_arr[40], coreid, 40) \
            HNA_PROF_COPY_VAR(prof_elem_arr[41], coreid, 41) \
            HNA_PROF_COPY_VAR(prof_elem_arr[42], coreid, 42) \
            HNA_PROF_COPY_VAR(prof_elem_arr[43], coreid, 43) \
            HNA_PROF_COPY_VAR(prof_elem_arr[44], coreid, 44) \
            HNA_PROF_COPY_VAR(prof_elem_arr[45], coreid, 45) \
            HNA_PROF_COPY_VAR(prof_elem_arr[46], coreid, 46) \
            HNA_PROF_COPY_VAR(prof_elem_arr[47], coreid, 47) \
            HNA_PROF_COPY_VAR(prof_elem_arr[48], coreid, 48) \
            HNA_PROF_COPY_VAR(prof_elem_arr[49], coreid, 49) \
            HNA_PROF_COPY_VAR(prof_elem_arr[50], coreid, 50) \
            HNA_PROF_COPY_VAR(prof_elem_arr[51], coreid, 51) \
            HNA_PROF_COPY_VAR(prof_elem_arr[52], coreid, 52) \
            HNA_PROF_COPY_VAR(prof_elem_arr[53], coreid, 53) \
            HNA_PROF_COPY_VAR(prof_elem_arr[54], coreid, 54) \
            HNA_PROF_COPY_VAR(prof_elem_arr[55], coreid, 55) \
            HNA_PROF_COPY_VAR(prof_elem_arr[56], coreid, 56) \
            HNA_PROF_COPY_VAR(prof_elem_arr[57], coreid, 57) \
            HNA_PROF_COPY_VAR(prof_elem_arr[58], coreid, 58) \
            HNA_PROF_COPY_VAR(prof_elem_arr[59], coreid, 59) \
            HNA_PROF_COPY_VAR(prof_elem_arr[60], coreid, 60) \
            HNA_PROF_COPY_VAR(prof_elem_arr[61], coreid, 61) \
            HNA_PROF_COPY_VAR(prof_elem_arr[62], coreid, 62) \
            HNA_PROF_COPY_VAR(prof_elem_arr[63], coreid, 63)


HNA_PROF_DECLARE_ALL_VARS


void print_sorted_profiles(u_int32_t coreid, std::map<u_int64_t, hna_prof_elm>  &max_sorted_elems, std::map<u_int64_t, hna_prof_elm>  &avg_sorted_elems, std::map<u_int64_t, hna_prof_elm>  &counter_elems)
{
    // check if the core is active (if is there any profiling data for this core)
    if(!max_sorted_elems.size() && !counter_elems.size())
        return;

    static int counter = 0;
    counter++;
    std::cout<<"id: "<<counter<<std::endl;
    fout<<"id: "<<counter<<" ======================= profile for core: "<<coreid<<" ========================="<<std::endl;
    fout<<std::endl;
    fout<<"\t############ maximum sorted profiles "<<std::endl;
    for(auto it: max_sorted_elems)
    {
        if(it.second.max_time)
            fout<<"\tid: "<< it.second.id <<" count: "<<it.second.cnt<<" current_time: "<<it.second.current_time<<" max_time: "<<it.second.max_time<<", avg_time: "<<it.second.avg_time<<"\n";
    }

    fout<<"\n\t++++++++++++ average sorted profiles "<<std::endl;
    for(auto it: avg_sorted_elems)
    {
        if(it.second.max_time)
            fout<<"\tid: "<< it.second.id <<" count: "<<it.second.cnt<<" current_time: "<<it.second.current_time<<" max_time: "<<it.second.max_time<<", avg_time: "<<it.second.avg_time<<"\n";
    }

    if(!counter_elems.size())
        return;
    fout<<"\n\t############ Counters "<<std::endl;
    for(auto it: counter_elems)
    {
        if(it.second.cnt)
            fout<<"\tid: "<< it.second.id <<" count: "<<it.second.cnt<<" count_rate: "<<it.second.avg_time<<"\n";
    }
    
    fout<<"\n\n";
    fout.flush();

}

void print_tot_avg(std::map<u_int16_t, hna_prof_elm> &tot_avg)
{
    fout<<"==========================================tot avg===================================="<<std::endl;
    for(auto it: tot_avg)
    {
        fout<<"\tid: "<< it.second.id <<" average_time: "<<it.second.sum_time/it.second.cnt<<std::endl;
    }
    fout.flush();
}

void hna_profile_init()
{
    fout.open("/tmp/hna_profile.txt");
}

void hna_profile_show_res()
{
    static u_int64_t last_counter[HNA_PROFILE_MAX_CORES][HNA_PROFILE_MAX_CORES];
    std::map<u_int16_t, hna_prof_elm> tot_avg;
    hna_prof_elm prof_elems[HNA_PROFILE_MAX_VAR];
    std::map<u_int64_t, hna_prof_elm>  max_sorted_elems;
    std::map<u_int64_t, hna_prof_elm>  avg_sorted_elems;
    std::map<u_int64_t, hna_prof_elm>  counter_elems;

    for(u_int32_t coreid=0; coreid< HNA_PROFILE_MAX_CORES; coreid++)
    {
        HNA_PROF_COPY_VAR_ARR(prof_elems, coreid);
        for(u_int32_t i=0; i< HNA_PROFILE_MAX_VAR; i++)
        {
            if(!prof_elems[i].cnt)
                continue;
            if(prof_elems[i].type == hna_elemtype_timer)
            {
                max_sorted_elems[prof_elems[i].max_time].cnt          = prof_elems[i].cnt;
                max_sorted_elems[prof_elems[i].max_time].id           = prof_elems[i].id;
                max_sorted_elems[prof_elems[i].max_time].current_time = prof_elems[i].current_time;
                max_sorted_elems[prof_elems[i].max_time].avg_time     = prof_elems[i].avg_time;
                max_sorted_elems[prof_elems[i].max_time].max_time     = prof_elems[i].max_time;

                avg_sorted_elems[prof_elems[i].avg_time].cnt          = prof_elems[i].cnt;
                avg_sorted_elems[prof_elems[i].avg_time].id           = prof_elems[i].id;
                avg_sorted_elems[prof_elems[i].avg_time].current_time = prof_elems[i].current_time;
                avg_sorted_elems[prof_elems[i].avg_time].avg_time     = prof_elems[i].avg_time;
                avg_sorted_elems[prof_elems[i].avg_time].max_time     = prof_elems[i].max_time;

                if(!tot_avg.count(prof_elems[i].id)) // if first time for this profile
                {
                    tot_avg[prof_elems[i].id].sum_time = 0;
                    tot_avg[prof_elems[i].id].cnt = 0;
                }
                
                tot_avg[prof_elems[i].id].id = prof_elems[i].id;
                tot_avg[prof_elems[i].id].sum_time += prof_elems[i].avg_time;
                tot_avg[prof_elems[i].id].cnt++;

            }
            else 
            {
                // do the calculation for counter rate
                prof_elems[i].avg_time = prof_elems[i].cnt - last_counter[coreid][i];
                last_counter[coreid][i] = prof_elems[i].cnt;

                counter_elems[prof_elems[i].cnt].cnt = prof_elems[i].cnt;
                counter_elems[prof_elems[i].cnt].id = prof_elems[i].id;
                counter_elems[prof_elems[i].cnt].avg_time = prof_elems[i].avg_time;
            }
        }

        print_sorted_profiles(coreid, max_sorted_elems, avg_sorted_elems, counter_elems);

        max_sorted_elems.clear();
        avg_sorted_elems.clear();
        counter_elems.clear();
    }

    print_tot_avg(tot_avg);
}