/*
 * =====================================================================================
 *
 *       Filename:  testapp.c
 *
 *    Description:  This file represents the Test application to test graph topology creation
 *
 *        Version:  1.0
 *        Created:  Wednesday 18 September 2019 04:41:41  IST
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

/* Visit my Website for more wonderful assignments and projects :
 * https://csepracticals.wixsite.com/csepracticals
 * if above URL dont work, then try visit : https://csepracticals.com*/

#include "CommandParser/libcli.h"
#include "graph.h"
#include "comm.h"
#include <string.h>
#include <unistd.h>

/* KHAI BÁO TOÀN CỤC: Biến topo phải là global để network_cli.c có thể 'extern' */
extern graph_t *build_first_topo();
extern void network_init_cli();

graph_t *topo = NULL;

int 
main(int argc, char **argv){

    network_init_cli();
    
    topo = build_first_topo();

    /* Cho luồng receiver thread có thời gian khởi động */
    sleep(2);

    /* 1. Lấy con trỏ của nút R0 (Nút gửi). Topology hiện tại đặt tên là "R0_re" */
    node_t *snode = get_node_by_node_name(topo, "R0_re");

    /* 2. Lấy con trỏ của cổng eth0/0 thuộc nút R0 (Cổng gửi) */
    interface_t *oif = get_node_if_by_name(snode, "eth0/0");

    /* 3. Tạo dữ liệu giả và gọi API gửi gói tin */
    char msg[] = "Hello, how are you?";
    send_pkt_out(msg, strlen(msg), oif);

    start_shell();
    return 0;
}