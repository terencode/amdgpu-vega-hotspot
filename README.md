## AMDGPU/Radeon HotSpot (ASIC_MAX) temperature patch

This simple patch introduces the additional temperature into hardware monitor:

* temp2_input - (ASIC_MAX temperature) GPU hot spot temperature

Exactly, this is an aggregated value, the maximal temperature from the internal sensors.

Currently, this patch is for kernels 4.10 - 4.17.
This temperature input will be added for all discrete graphics cards (but not APUs)
except older than GCN 1.0 (Radeon HD 4000/3000/4000/5000/6000).

The temp1_input is graphics card's main (CTF) temperature.

### Patches

* vega10_extratemps-X.X.X.patch - original VEGA 10 patch (apply only for VEGA)
* amdgpu_extratemps-X.X.X.patch - AMDGPU driver patch for all graphics cards
* radeon_extratemps-X.X.X.patch - Radeon driver patch for GCN1.0/1.1 graphics cards
* amdgpu-pro-extratemps-X.XX.patch - AMDGPU-PRO driver patch

### Applying patch

Enter to your linux kernel directory and enter command:

```
patch -p1 < amdgpu_extratemps-X.Y.Z.patch
patch -p1 < radeon_extratemps-X.Y.Z.patch
```

and you can make your kernel.

for AMDGPU-PRO just enter to amdgpu-pro module source (`/usr/src/amdgpu-XXX` or
`/usr/src/amdgpu-pro-XXX`) directory and enter command:

```
patch -p1 < amdgpu-pro-extratemps-X.XX.patch
```

### Rebuilding AMDGPU-PRO module

The AMDGPU-PRO driver uses DKMS to manage its module. Before rebuilding try to check
amdgpu pro module:

```
dkms status
```

Now, you enter three commands:

```
dkms remove -m MODULENAME -v MODVERSION -k KERNEL
dkms build -m MODULENAME -v MODVERSION -k KERNEL
dkms install -m MODULENAME -v MODVERSION -k KERNEL
```

where `MODULENAME` is your amdgpu-pro module name (amdgpu or amdgpu-pro), MODVERSION
is your module version (17.30-XXXXX) and KERNEL is your kernel. All these informations
will be printed by `dkms status`. After all, reboot system.

### How to read sensor

Just by putting command (if you have configured lm-sensors):

```
sensors
```

or by reading from file in sysfs:

```
cat /sys/class/drm/cardX/device/hwmon/hwmonY/temp2_input
```

where cardX is your VEGA graphic card and hwmon is your hwmon for this card.

New version of the AMDCOVC 0.3.9.2 can read extra temperatures and
you can use this tool to read a hot spot temperature.

### AMDGPU-PRO

### Linux directory

The linux-4.16.1 directory holds amdgpu driver with applied changes.
This is not whole Linux kernel sources.

### Previous version

The initial version of this patch provided two extra temperature sensors
(first was doubling standard temp1_input and second was the hot spot temperature sensor).
