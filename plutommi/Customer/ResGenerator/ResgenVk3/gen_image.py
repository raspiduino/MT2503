########################################################
#   1. gen xml image for system resgenerator
#   2. copy file to image zip
########################################################
from read_config import g_bg_list1
from read_config import g_bg_list2
from read_config import g_bg_path_list1
from read_config import g_bg_path_list2
g_root_path = "plutommi\\"
g_path1 = "Service\\vk3Srv\\Res\\"

def copyImage():
    lcd_size = get_lcd_size()
    # this part not implement.

def getSlicePath(path, slice_root):
    temp_str = ""

    index = path.find(slice_root)

    if index == -1:
        return temp_str
    
    temp_str = path[0:index + len(slice_root)]
    return temp_str
        


        
def addImageDefines():
    b = True
    add_begin = 'RESOURCE_BASE_RANGE'
    add_end = ['/* please add new resource base table above this line */','RESOURCE_BASE_TABLE_END()']
    root_f = '../../../../'
    mmi_res_range_name = 'plutommi\\mmi\\Inc\\mmi_res_range_def.h'
    line_list = []
    file_path = os.path.join(root_f, mmi_res_range_name)
    m = open(file_path,'r')
    f = m.readlines()
    for line in f:
        if line in add_begin:
            str = '''RESOURCE_BASE_RANGE(SRV_VK3, %s),\n'''%(len(g_bg_list)+20)
            line_list.append(str)
            line_list.append(line)
        if line in add_end and b:
            b = False
            str = '''

/****************************************************************************
*  vkv3 res
*****************************************************************************/
#define    VIRTUAL_KEYBOARD_BASE    ( (U16) GET_RESOURCE_BASE(SRV_VK3))
#define SRV_CNMGR_BASE_MAX  ((U16) GET_RESOURCE_MAX(SRV_VK3))
RESOURCE_BASE_TABLE_ITEM_PATH(SRV_VK3, ".\\service\\Vk3Srv\\Res\\")
/*****************************************************************************/

'''
            line_list.append(str)
            line_list.append(line)
        else:
            line_list.append(line)
    m.close()
    file = open(file_path,'w')
    for i in line_list:
        file.write(i)
    file.close()
def main():
    genXmlImage()

if __name__ == "__main__":
    main()
    
    
