from PIL import Image
import numpy as np
import os

def image_to_matrix(image_path, output_path, target_width=50, target_height=50):
    """
    将图片转换为颜色矩阵并保存到文件
    
    参数:
        image_path: 输入图片路径
        output_path: 输出矩阵文件路径
        target_width: 目标宽度(默认50)
        target_height: 目标高度(默认50)
    """
    try:
        # 打开图片并调整大小
        img = Image.open(image_path)
        img = img.resize((target_width, target_height))
        
        # 转换为RGB模式(确保有颜色通道)
        if img.mode != 'RGB':
            img = img.convert('RGB')
        
        # 转换为numpy数组
        img_array = np.array(img)
        
        # 转换为16位RGB565格式(64K色)
        def rgb_to_565(r, g, b):
            return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
        
        # 创建颜色矩阵
        color_matrix = []
        for row in img_array:
            matrix_row = []
            for pixel in row:
                r, g, b = pixel
                color_565 = rgb_to_565(r, g, b)
                matrix_row.append(color_565)
            color_matrix.append(matrix_row)
        
        # 写入文件
        with open(output_path, 'w') as f:
            f.write(f"// 图像矩阵 {target_width}x{target_height} (RGB565格式)\n")
            f.write(f"unsigned int image_matrix[{target_height}][{target_width}] = {{\n")
            for row in color_matrix:
                f.write("    {")
                f.write(", ".join(f"0x{color:04X}" for color in row))
                f.write("},\n")
            f.write("};\n")
        
        print(f"转换成功! 矩阵已保存到 {output_path}")
        print(f"在C代码中使用: Putpixel64k(x, y, image_matrix[y][x]);")
        
    except Exception as e:
        print(f"错误: {str(e)}")

if __name__ == "__main__":
    # 使用示例
    input_image = input("../box.png")
    output_file = input("../INCLUDE/box.h")
    width = int(input("请输入目标宽度(默认50): ") or 50)
    height = int(input("请输入目标高度(默认50): ") or 50)
    
    image_to_matrix(input_image, output_file, width, height)