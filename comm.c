/*
 * =====================================================================================
 *
 *       Filename:  comm.c
 *
 *    Description:  This file contains the routines to implement the communication between nodes
 *
 *        Version:  1.0
 *        Created:  Thursday 19 September 2019 10:31:35  IST
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Er. Abhishek Sagar, Networking Developer (AS), sachinites@gmail.com
 *        Company:  Brocade Communications(Jul 2012- Mar 2016), Current : Juniper Networks(Apr 2017 - Present)
 *        
 *        This file is part of the NetworkGraph distribution (https://github.com/sachinites).
 *        Copyright (c) 2017 Abhishek Sagar.
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU General Public License as published by  
 *        the Free Software Foundation, version 3.
 *
 *        This program is distributed in the hope that it will be useful, but 
 *        WITHOUT ANY WARRANTY; without even the implied warranty of 
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 *        General Public License for more details.
 *
 *        You should have received a copy of the GNU General Public License 
 *        along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */

#include "graph.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned int udp_port_number = 40000;

static unsigned int 
get_next_udp_port_number(){
    
    return udp_port_number++;
}

void
init_udp_socket(node_t *node){

    if(node->udp_port_number)
        return;
    
    node->udp_port_number = get_next_udp_port_number();
     
    int udp_sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP );
    
    if(udp_sock_fd == -1){
        printf("Socket Creation Failed for node %s\n", node->node_name);
        return;   
    }

    struct sockaddr_in node_addr;
    node_addr.sin_family      = AF_INET;
    node_addr.sin_port        = node->udp_port_number;
    node_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(udp_sock_fd, (struct sockaddr *)&node_addr, sizeof(struct sockaddr)) == -1) {
        printf("Error : socket bind failed for Node %s\n", node->node_name);
        return;
    }

    node->udp_sock_fd = udp_sock_fd;
}