#include "CommandParser/libcli.h"
#include "CommandParser/cmdtlv.h"
#include "cmdcodes.h"
#include "graph.h"

/* Import biến topology toàn cục từ testapp.c */
extern graph_t *topo;

/* 1. Hàm Xử lý Backend (Callback Handler) */
int show_nw_topology_handler(param_t *param, ser_buff_t *tlv_buf, op_mode enable_or_disable) {
    int cmd_code = EXTRACT_CMD_CODE(tlv_buf);
    
    switch(cmd_code) {
        case CMDCODE_SHOW_NW_TOPOLOGY:
            /* Gọi hàm in đồ thị mạng đã có sẵn trong dự án */
            dump_nw_graph(topo);
            break;
        default:
            break;
    }
    return 0;
}

/* 2. Hàm Khởi tạo CLI cho Network */
void network_init_cli() {
    init_libcli();
    
    param_t *show   = libcli_get_show_hook();
    param_t *config = libcli_get_config_hook();
    
    /* Đăng ký lệnh: show topology */
    {
        static param_t topology;
        init_param(&topology, CMD, "topology", show_nw_topology_handler, 0, INVALID, 0, "Dump Complete Network Topology");
        libcli_register_param(show, &topology);
        set_param_cmd_code(&topology, CMDCODE_SHOW_NW_TOPOLOGY);
    }
    
    support_cmd_negation(config);
}