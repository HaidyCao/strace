cmake_minimum_required(VERSION 3.10.2)

project(strace)

set(STRACE_SOURCE

        access.c
        affinity.c
        aio.c
        basic_filters.c
        bind.c
        bjm.c
        block.c
        bpf.c
        bpf_filter.c
        bpf_seccomp_filter.c
        bpf_sock_filter.c
        btrfs.c
        cacheflush.c
        capability.c
        chdir.c
        chmod.c
        clone.c
        copy_file_range.c
        count.c
        delay.c
        desc.c
        dirent.c
        dirent64.c
        dm.c
        dyxlat.c
        epoll.c
        error_prints.c
        evdev.c
        evdev_mpers.c
        eventfd.c
        execve.c
        fadvise.c
        fallocate.c
        fanotify.c
        fchownat.c
        fcntl.c
        fetch_bpf_fprog.c
        fetch_indirect_syscall_args.c
        fetch_struct_flock.c
        fetch_struct_keyctl_kdf_params.c
        fetch_struct_mmsghdr.c
        fetch_struct_msghdr.c
        fetch_struct_stat.c
        fetch_struct_stat64.c
        fetch_struct_statfs.c
        fetch_struct_xfs_quotastat.c
        file_handle.c
        file_ioctl.c
        filter_qualify.c
        flock.c
        fstatfs.c
        fstatfs64.c
        fs_x_ioctl.c
        futex.c
        getcpu.c
        getcwd.c
        getpagesize.c
        getrandom.c
        get_robust_list.c
        hdio.c
        hostname.c
        inotify.c
        inotify_ioctl.c
        io.c
        ioctl.c
        ioperm.c
        iopl.c
        ioprio.c
        ipc.c
        ipc_msg.c
        ipc_msgctl.c
        ipc_sem.c
        ipc_shm.c
        ipc_shmctl.c
        kcmp.c
        kexec.c
        keyctl.c
        kvm.c
        ldt.c
        link.c
        listen.c
        lookup_dcookie.c
        loop.c
        lseek.c
        mem.c
        membarrier.c
        memfd_create.c
        mknod.c
        mmap_cache.c
        mmap_notify.c
        mmsghdr.c
        mount.c
        mq.c
        msghdr.c
        mtd.c
        nbd_ioctl.c
        net.c
        netlink.c
        netlink_crypto.c
        netlink_inet_diag.c
        netlink_kobject_uevent.c
        netlink_netfilter.c
        netlink_netlink_diag.c
        netlink_packet_diag.c
        netlink_route.c
        netlink_selinux.c
        netlink_smc_diag.c
        netlink_sock_diag.c
        netlink_unix_diag.c
        nlattr.c
        nsfs.c
        numa.c
        number_set.c
        oldstat.c
        open.c
        pathtrace.c
        perf.c
        perf_ioctl.c
        personality.c
        pkeys.c
        poll.c
        prctl.c
        print_aio_sigset.c
        print_dev_t.c
        print_group_req.c
        print_ifindex.c
        print_mac.c
        print_mq_attr.c
        print_msgbuf.c
        print_sigevent.c
        print_sg_req_info.c
        print_statfs.c
        print_struct_stat.c
        print_time.c
        print_timespec.c
        print_timeval.c
        print_timex.c
        printmode.c
        printrusage.c
        printsiginfo.c
        process.c
        process_vm.c
        ptp.c
        quota.c
        readahead.c
        readlink.c
        reboot.c
        renameat.c
        resource.c
        retval.c
        rtc.c
        rtnl_addr.c
        rtnl_addrlabel.c
        rtnl_dcb.c
        rtnl_link.c
        rtnl_mdb.c
        rtnl_neigh.c
        rtnl_neightbl.c
        rtnl_netconf.c
        rtnl_nsid.c
        rtnl_route.c
        rtnl_rule.c
        rtnl_tc.c
        rtnl_tc_action.c
        rt_sigframe.c
        rt_sigreturn.c
        sched.c
        scsi.c
        seccomp.c
        sendfile.c
        sg_io_v3.c
        sg_io_v4.c
        shutdown.c
        sigaltstack.c
        signal.c
        signalfd.c
        sigreturn.c
        sock.c
        sockaddr.c
        socketcall.c
        socketutils.c
        sram_alloc.c
        stat.c
        stat64.c
        statfs.c
        statfs64.c
        statx.c
        strace.c
        string_to_uint.c
        swapon.c
        sync_file_range.c
        sync_file_range2.c
        syscall.c
        sysctl.c
        sysinfo.c
        syslog.c
        sysmips.c
        term.c
        time.c
        times.c
        truncate.c
        ubi.c
        ucopy.c
        uid16.c
        uid.c
        umask.c
        umount.c
        uname.c
        upeek.c
        upoke.c
        userfaultfd.c
        ustat.c
        util.c
        utime.c
        utimes.c
        v4l2.c
        wait.c
        xattr.c
        xlat.c
        xmalloc.c
        )

message("------------------------------${PREFAB}-----------------------------------")

if("${PREFAB}" STREQUAL "1")
    message("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")

    add_library(strace SHARED ${STRACE_SOURCE})
    target_compile_definitions(strace PUBLIC -DSTRACE_LIB)
else()
    add_library(strace-shared SHARED ${STRACE_SOURCE})
    add_library(strace-static STATIC ${STRACE_SOURCE})
    add_executable(strace ${STRACE_SOURCE})
    message("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")

    target_compile_definitions(strace-shared PUBLIC -DSTRACE_LIB)
    target_compile_definitions(strace-static PUBLIC -DSTRACE_LIB)
    target_compile_definitions(strace PUBLIC -DSTRACE_EXE)
endif()

add_definitions(-DHAVE_CONFIG_H -DSIZEOF_KERNEL_LONG_T=SIZEOF_LONG -DSIZEOF_OFF_T=SIZEOF_LONG)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wimplicit-function-declaration -Wno-initializer-overrides -Wno-missing-field-initializers -Wno-pointer-arith -Wno-unused-parameter -Wno-sign-compare -fno-strict-aliasing")

message("CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")

if (ANDROID)
    message("build for android")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__USE_GNU")
    remove_definitions("HAVE_FPUTS_UNLOCKED" "HAVE_PROCESS_VM_READV" "HAVE_STPCPY")
    IF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "aarch64")
        set(TARGET_BIT "64")
        add_definitions(-DAARCH64=1 -DHAVE_STATIC_ASSERT)

        include_directories(. linux/aarch64 linux)
    ELSEIF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "armv7-a")
        set(TARGET_BIT "32")
        add_definitions(-DARM=1 -DHAVE_STRUCT___OLD_KERNEL_STAT=1 -DHAVE__STATIC_ASSERT)

        include_directories(. linux/arm linux)
    ELSEIF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
        set(TARGET_BIT "64")
        add_definitions(-DX86_64=1 -DHAVE_STATIC_ASSERT)

        include_directories(. linux/x86_64 linux)
    ELSEIF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "i686")
        set(TARGET_BIT "32")
        add_definitions(-DI386=1 -DHAVE_STRUCT___OLD_KERNEL_STAT=1 -DHAVE_STATIC_ASSERT)

        include_directories(. linux/i386 linux)
    ELSE ()
        set(TARGET_BIT "32")
        message("not support")
    ENDIF ()
else ()
    if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
        set(TARGET_BIT "64")
        add_definitions(-DX86_64=1 -DHAVE_STATIC_ASSERT)

        include_directories(. linux/x86_64 linux)
    ELSEIF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "i686")
        set(TARGET_BIT "32")
        add_definitions(-DI386=1 -DHAVE_STRUCT___OLD_KERNEL_STAT=1 -DHAVE_STATIC_ASSERT)

        include_directories(. linux/i386 linux)
    endif ()
    #    if ()
    #        message("64 bit")
    #    ELSE ()
    #        message("32 bit")
    #    endif ()
    target_link_libraries(
            strace

            -lrt
    )
endif ()

if (${TARGET_BIT} STREQUAL "64")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSIZEOF_LONG_LONG=8 -DSIZEOF_LONG=8 -DSIZEOF_RLIM_T=8")
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSIZEOF_LONG_LONG=8 -DSIZEOF_LONG=4 -DSIZEOF_RLIM_T=4 -DHAVE_STRUCT_STAT64=1")
endif ()