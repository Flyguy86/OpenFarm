# OpenFarm

# Routing wifi / cellular USB tether / VPN / Routers / WDS / Multi WAN / 
- RT-N66U / Tomato Shibby firmware replacement
 * https://learntomato.com/how-to-flash-a-router-tomato-firmware-shibby-mod/
 * http://tomato.groov.pl/download/K26RT-N/build5x-138-MultiWAN/Asus%20RT-N66u%2064k/
- Wireless Bridging
 * http://vpnpick.com/choose-wireless-bridge-mode-tomato-network/
 * https://learntomato.com/setup-wireless-repeater-wds-bridge-tomato/
- OpenVPN key cert generation
 *
 *
- USB Tethering
 * https://gist.github.com/dferg/2278196d736d5b367682
 * http://tomatousb.org/forum/t-259025/usb-android-tethering-modules
 * http://unix.stackexchange.com/questions/60078/find-out-which-modules-are-associated-with-a-usb-device

# Robots Erle
- Arial Survey 
 * 
 * http://tomato.groov.pl/download/K26RT-N/build5x-138-MultiWAN/Asus%20RT-N66u%2064k/
- Rover, Lawn tractor
 * http://vpnpick.com/choose-wireless-bridge-mode-tomato-network/
 * https://learntomato.com/setup-wireless-repeater-wds-bridge-tomato/
- Simulators
 *
 *
- Ardupilot & AMP Planner
 * https://gist.github.com/dferg/2278196d736d5b367682
 * http://tomatousb.org/forum/t-259025/usb-android-tethering-modules





# ZoneMinder - Remote Video monitoring
- ZM Hardware Compatability list,  Most IP Cameras work just takes a bit of effort to set them up.
 * https://wiki.zoneminder.com/Hardware_Compatibility_List#X10_Devices
- Debian installation guide
 * https://zoneminder.readthedocs.io/en/stable/installationguide/index.html
- [ ] Create snapshot script to generate timelapse, Save to NFS drive

# FileServer Synology (Cheaper/Hackable RAID device)
- How to install ipkg tool, avalibel packages ipkg update
 * http://rescene.wikidot.com/synology-ipkg
- Debian Chroot
 * https://markpith.wordpress.com/2015/10/26/debian-chroot-on-synology-nas/

# RPI farm sensor Aggrigator
- network sniffer, for sensors hosting data in JSON format
- AI to respond based on sensor input to control Irrigation and robot response
- Run Readonly Root file system
 * https://hallard.me/raspberry-pi-read-only/
- [x] Set Wifi & Host Name in /boot/config.txt
- [x] Set Locale to US
- [x] Use DHCP for Non-sever Devices, IPCams
- [x] Set Static IP for sever devices, OpenSprinkler, ZoneMonitor, Farm AI Middleware
- [x] Install current version of Node.js NPM
- [x] Install Particle-cli  via NPM
- [x] Install NFS cliet
- [x] Remote Mount NFS filesystem, /home/camera <-RW /home/scripts <-RO /home/misc <- RW 
- [x] Bash script to create Folder in Each NFS mount based on HostName, Script checks write permissions as well
- [x] Network Connectivity script, & reboot
- [x] VPN for Servers Or is it all done through middleware ??? Eventually.
- [x] Read only root for OpenSprinkler & Camera setups
- [x] RPi-Cam For Camera setup ?  * DeitPi-Cam software
- [x] Install GIT
- [x] Install tcpdump, nload, iftop, OpenSSH client

# RPI Label printer 
- Dynmo 450
 * https://www.hmazter.com/2013/05/raspberry-pi-printer-server-for-labelwriter

# Wireless sensor nodes
- Moisture
 * https://www.tindie.com/products/miceuz/i2c-soil-moisture-sensor/
  * Chirp I2C Moisture sensor Base Calibration,  615 = Glass of water, 320 = No contact , 460 = Damp soil
 - Error Checking, the sensor values
  * http://www.mathsisfun.com/data/percentage-difference-vs-error.html
- chrip github
 * https://github.com/Miceuz/i2c-moisture-sensor
- Particle Photon
 * https://docs.particle.io/reference/firmware/core/

# Wireless Dose Reservoiur control modual.
- My Hardware breakout board for the particle photon
 * Still need to link and upload the link to purchace.


# RPI - OpenSprinkler Irrigation REST controller  
- Product purchace
 * https://opensprinkler.com/product/opensprinkler-pi/
- RPI Software Install
 * https://openthings.freshdesk.com/support/solutions/articles/5000631599-installing-and-updating-the-unified-firmware
- OS GitHub
 * https://github.com/rayshobby/opensprinkler
- OS API refernce PDF
 * https://openthings.freshdesk.com/support/solutions/articles/5000716363-api-document-firmware-2-1-7-current-
- Add RF control for remote Socket control
 * http://rayshobby.net/opensprinkler-firmware-2-1-1-new-feature-control-remote-power-sockets/
