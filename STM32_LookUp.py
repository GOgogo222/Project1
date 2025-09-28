# stm32_abbr_lookup.py
"""
STM32 英文缩写查询工具
功能：快速查询STM32学习中遇到的各种英文缩写
"""

import os

# 完整的STM32缩写数据库
STM32_ABBR_DATABASE = {
    # 核心概念与架构
    "ARM": {
        "english": "Advanced RISC Machine",
        "chinese": "高级精简指令集机器",
        "description": "STM32芯片的核心架构，定义了基础的指令集和工作方式",
        "category": "核心架构"
    },
    "RISC": {
        "english": "Reduced Instruction Set Computer",
        "chinese": "精简指令集计算机",
        "description": "ARM架构的设计哲学，指令简单，执行效率高",
        "category": "核心架构"
    },
    "AAPCS": {
        "english": "ARM Architecture Procedure Call Standard",
        "chinese": "ARM架构过程调用标准",
        "description": "定义了函数调用时如何传递参数、返回值等规则",
        "category": "核心架构"
    },
    
    # 时钟与电源
    "RCC": {
        "english": "Reset and Clock Control",
        "chinese": "复位和时钟控制",
        "description": "核心外设，所有外设的时钟都由它来管理和开关",
        "category": "时钟电源"
    },
    "HSE": {
        "english": "High Speed External clock",
        "chinese": "高速外部时钟",
        "description": "通常指外接的8MHz晶振，是系统主时钟的常见来源",
        "category": "时钟电源"
    },
    "HSI": {
        "english": "High Speed Internal clock",
        "chinese": "高速内部时钟",
        "description": "芯片内部的RC振荡器（通常16MHz），精度不如HSE，但无需外接元件",
        "category": "时钟电源"
    },
    "LSE": {
        "english": "Low Speed External clock",
        "chinese": "低速外部时钟",
        "description": "通常指外接的32.768kHz晶振，主要用于RTC",
        "category": "时钟电源"
    },
    "LSI": {
        "english": "Low Speed Internal clock",
        "chinese": "低速内部时钟",
        "description": "芯片内部的低速RC振荡器（约32kHz），用于独立看门狗和RTC的备用时钟",
        "category": "时钟电源"
    },
    "RTC": {
        "english": "Real-Time Clock",
        "chinese": "实时时钟",
        "description": "即使主系统断电，也能依靠备用电池继续走时的时钟",
        "category": "时钟电源"
    },
    
    # 通信接口
    "GPIO": {
        "english": "General Purpose Input/Output",
        "chinese": "通用输入/输出端口",
        "description": "最基础的外设，用于控制引脚的电平高低或读取引脚状态",
        "category": "通信接口"
    },
    "AFIO": {
        "english": "Alternate Function I/O",
        "chinese": "复用功能IO",
        "description": "当GPIO引脚用于其他外设功能（如UART, SPI）时的配置",
        "category": "通信接口"
    },
    "UART": {
        "english": "Universal Asynchronous Receiver/Transmitter",
        "chinese": "通用异步收发器",
        "description": "最基础的串行通信协议，异步，全双工",
        "category": "通信接口"
    },
    "USART": {
        "english": "Universal Synchronous/Asynchronous Receiver/Transmitter",
        "chinese": "通用同步/异步收发器",
        "description": "在UART基础上增加了同步模式，功能更强",
        "category": "通信接口"
    },
    "I2C": {
        "english": "Inter-Integrated Circuit",
        "chinese": "集成电路总线",
        "description": "一种简单的双向两线制同步串行总线，多用于连接传感器",
        "category": "通信接口"
    },
    "SPI": {
        "english": "Serial Peripheral Interface",
        "chinese": "串行外设接口",
        "description": "一种高速的全双工同步串行总线，通常比I2C快",
        "category": "通信接口"
    },
    "CAN": {
        "english": "Controller Area Network",
        "chinese": "控制器局域网",
        "description": "一种抗干扰能力极强的总线，主要用于汽车和工业领域",
        "category": "通信接口"
    },
    "USB": {
        "english": "Universal Serial Bus",
        "chinese": "通用串行总线",
        "description": "用于与PC或其他USB主机/设备通信",
        "category": "通信接口"
    },
    
    # 核心外设
    "EXTI": {
        "english": "External Interrupts",
        "chinese": "外部中断",
        "description": "允许GPIO引脚在电平变化时触发中断，用于响应外部事件",
        "category": "核心外设"
    },
    "TIM": {
        "english": "Timer",
        "chinese": "定时器",
        "description": "功能极其强大的外设，用于精确计时、产生PWM波、输入捕获等",
        "category": "核心外设"
    },
    "NVIC": {
        "english": "Nested Vectored Interrupt Controller",
        "chinese": "嵌套向量中断控制器",
        "description": "中断系统的核心，负责管理所有中断的优先级和响应",
        "category": "核心外设"
    },
    "DMA": {
        "english": "Direct Memory Access",
        "chinese": "直接内存访问",
        "description": "允许数据在外设和内存间不经过CPU直接传输，大大减轻CPU负担",
        "category": "核心外设"
    },
    "ADC": {
        "english": "Analog to Digital Converter",
        "chinese": "模数转换器",
        "description": "将模拟信号转换为数字信号的模块",
        "category": "核心外设"
    },
    
    # 调试与开发
    "IDE": {
        "english": "Integrated Development Environment",
        "chinese": "集成开发环境",
        "description": "用于编程、编译、调试的软件，如Keil, IAR, STM32CubeIDE",
        "category": "调试开发"
    },
    "JTAG": {
        "english": "Joint Test Action Group",
        "chinese": "联合测试行动小组",
        "description": "一种标准的芯片调试和编程接口",
        "category": "调试开发"
    },
    "SWD": {
        "english": "Serial Wire Debug",
        "chinese": "串行线调试",
        "description": "ARM推出的两线制调试协议，比JTAG占用引脚少，是STM32调试的首选",
        "category": "调试开发"
    },
    
    # 内存与总线
    "FSMC": {
        "english": "Flexible Static Memory Controller",
        "chinese": "可变静态存储控制器",
        "description": "用于扩展外部存储器，如SRAM, NOR Flash，以及驱动LCD屏",
        "category": "内存总线"
    },
    
    # 程序模型与系统
    "PC": {
        "english": "Program Counter",
        "chinese": "程序计数器",
        "description": "指向当前正在执行的指令的地址",
        "category": "程序模型"
    },
    "LR": {
        "english": "Link Register",
        "chinese": "链接寄存器",
        "description": "存储函数返回的地址",
        "category": "程序模型"
    },
    "SP": {
        "english": "Stack Pointer",
        "chinese": "堆栈指针",
        "description": "指向当前栈顶",
        "category": "程序模型"
    },
    "ISR": {
        "english": "Interrupt Service Routine",
        "chinese": "中断服务程序",
        "description": "当中断发生时执行的函数",
        "category": "程序模型"
    },
    "RTOS": {
        "english": "Real Time Operating System",
        "chinese": "实时操作系统",
        "description": "如FreeRTOS, μC/OS，用于管理多个任务",
        "category": "程序模型"
    }
}

def clear_screen():
    """清空屏幕"""
    os.system('cls' if os.name == 'nt' else 'clear')

def display_welcome():
    """显示欢迎信息"""
    print("=" * 50)
    print("      STM32 英文缩写查询工具")
    print("=" * 50)
    print("输入 'help' 查看帮助，'list' 查看所有缩写")
    print("输入 'quit' 退出程序")
    print("-" * 50)

def display_help():
    """显示帮助信息"""
    print("\n使用说明：")
    print("1. 直接输入缩写（如：GPIO, RCC, UART）进行查询")
    print("2. 输入 'list' 查看所有可查询的缩写")
    print("3. 输入 'categories' 按分类查看缩写")
    print("4. 输入 'search 关键词' 进行关键词搜索")
    print("5. 输入 'quit' 退出程序")

def display_all_abbreviations():
    """显示所有缩写"""
    print("\n所有可查询的缩写：")
    abbreviations = list(STM32_ABBR_DATABASE.keys())
    abbreviations.sort()
    
    for i in range(0, len(abbreviations), 5):
        line = abbreviations[i:i+5]
        print("  ".join(f"{abbr:8}" for abbr in line))
    
    print(f"\n总计: {len(abbreviations)} 个缩写")

def display_categories():
    """按分类显示缩写"""
    categories = {}
    for abbr, info in STM32_ABBR_DATABASE.items():
        category = info.get('category', '其他')
        if category not in categories:
            categories[category] = []
        categories[category].append(abbr)
    
    print("\n按分类查看：")
    for category, abbr_list in categories.items():
        print(f"\n{category} ({len(abbr_list)}个):")
        abbr_list.sort()
        for i in range(0, len(abbr_list), 8):
            line = abbr_list[i:i+8]
            print("  ".join(f"{abbr:8}" for abbr in line))

def search_by_keyword(keyword):
    """根据关键词搜索"""
    keyword = keyword.lower()
    results = []
    
    for abbr, info in STM32_ABBR_DATABASE.items():
        if (keyword in abbr.lower() or 
            keyword in info['english'].lower() or 
            keyword in info['chinese'].lower() or 
            keyword in info['description'].lower()):
            results.append((abbr, info))
    
    if results:
        print(f"\n找到 {len(results)} 个相关结果:")
        for abbr, info in results:
            display_abbr_info(abbr, info)
    else:
        print(f"\n未找到包含 '{keyword}' 的缩写")

def display_abbr_info(abbr, info):
    """显示缩写信息"""
    print(f"\n缩写: {abbr}")
    print(f"英文全称: {info['english']}")
    print(f"中文释义: {info['chinese']}")
    print(f"功能描述: {info['description']}")
    print(f"分类类别: {info.get('category', '未分类')}")
    print("-" * 50)

def main():
    """主函数"""
    clear_screen()
    display_welcome()
    
    while True:
        try:
            user_input = input("\n请输入命令或缩写: ").strip()
            
            if not user_input:
                continue
                
            if user_input.lower() in ['quit', 'exit', 'q']:
                print("感谢使用STM32缩写查询工具！")
                break
                
            elif user_input.lower() == 'help':
                display_help()
                
            elif user_input.lower() == 'list':
                display_all_abbreviations()
                
            elif user_input.lower() == 'categories':
                display_categories()
                
            elif user_input.lower().startswith('search '):
                keyword = user_input[7:].strip()
                if keyword:
                    search_by_keyword(keyword)
                else:
                    print("请输入搜索关键词")
                    
            else:
                abbr = user_input.upper()
                if abbr in STM32_ABBR_DATABASE:
                    display_abbr_info(abbr, STM32_ABBR_DATABASE[abbr])
                else:
                    print(f"未找到缩写 '{abbr}'")
                    print("提示：输入 'list' 查看所有可用缩写")
                    
        except KeyboardInterrupt:
            print("\n\n程序被用户中断")
            break
        except Exception as e:
            print(f"发生错误: {e}")

if __name__ == "__main__":
    main()