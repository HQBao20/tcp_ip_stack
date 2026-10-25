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

/* KHAI BÁO TOÀN CỤC: Biến topo phải là global để network_cli.c có thể 'extern' */
extern graph_t *build_first_topo();
extern void network_init_cli();

graph_t *topo = NULL;

int 
main(int argc, char **argv){

    network_init_cli();
    
    topo = build_first_topo();

    start_shell(); 
    return 0;
}