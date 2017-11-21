# -*- coding: utf-8 -*-
"""
Created on Mon Nov 20 20:54:48 2017

@author: Jacob
"""


import optirx as rx


dsock = rx.mkdatasock(ip_address='168.254.149.164',multicast_address='168.254.149.164', port=1511)
version = (2, 9, 0, 0)  # NatNet version to use
while True:
    data = dsock.recv(rx.MAX_PACKETSIZE)
    packet = rx.unpack(data, version=version)
    if type(packet) is rx.SenderData:
        version = packet.natnet_version
    print packet