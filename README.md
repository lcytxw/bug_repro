Repro steps:
1. cd linux-kernel-dir && make -j64

2. use this script to create a minial Debian-wheezy Linux image.
https://github.com/lcytxw/bug_repro/blob/master/wheezy.sh
this step got wheezy.img and ssh dir

3. install qemu and run
$ qemu-system-x86_64 -m 2048 -smp 1 -net nic -net user,host=10.0.2.10,hostfwd=tcp::42222-:22 -display none -serial stdio -no-reboot -enable-kvm -hda /path/to/wheezy.img -snapshot -kernel /path/to/arch/x86/boot/bzImage -append "console=ttyS0 earlyprintk=serial oops=panic nmi_watchdog=panic panic_on_warn=1 panic=86400 ftrace_dump_on_oops=orig_cpu rodata=n vsyscall=native net.ifnames=0 biosdevname=0 kvm-intel.nested=1 kvm-intel.unrestricted_guest=1 kvm-intel.vmm_exclusive=1 kvm-intel.fasteoi=1 kvm-intel.ept=1 kvm-intel.flexpriority=1 kvm-intel.vpid=1 kvm-intel.emulate_invalid_guest_state=1 kvm-intel.eptad=1 kvm-intel.enable_shadow_vmcs=1 kvm-intel.pml=1 kvm-intel.enable_apicv=1 root=/dev/sda"

4. scp -i /path/to/ssh/id_rsa -P 42222 repro root@localhost:/root/

5. ./repro

