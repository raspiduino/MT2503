import shutil
import os


def copyfiles():
    copy_list = ['virtual_keyboard3_res.h', 'virtual_keyboard3_define.h']
    file_path ='..\..\ResGenerator\debug\\res_out_put\\'
    copy_path = "..\..\..\..\\plutommi\\Service\\vk3Srv\inc\\"

    for i in copy_list:
        pt = file_path+i
        out_path = copy_path + i
        checkdir()
        if os.path.isfile(out_path):
            os.remove(out_path)        
        shutil.copy(pt, copy_path)
        
        

def checkdir():
    if not os.path.exists("..\..\..\..\\plutommi\\Service\\vk3Srv"):
        os.mkdir("..\..\..\..\\plutommi\\Service\\vk3Srv")
    if not os.path.exists("..\..\..\..\\plutommi\\Service\\vk3Srv\inc\\"):
        os.mkdir("..\..\..\..\\plutommi\\Service\\vk3Srv\inc\\")

    return

if __name__ == '__main__':
    copyfiles()
    
     
