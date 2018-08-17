运行环境：Qt5.6.1 MinGW 32bit
语言：C++
工程名:thoughtworks_exam
文档：main.cpp maze.h

运行单元测试：
	运行main.cpp进入控制台输入两行字符串(第一行为迷宫尺寸，以空格隔开；第二行为道路网格连通性定义，多个连通以分号;隔开)，回车输出渲染网络。
	若两行字符串中存在中文字符，或者有连通定义时输入单元数目不为两个，则输出字符串："Incorrect command format."。
	若两行字符串中无法转为数字，则输出字符串："Invalid number format."。
	若第二行字符串中数字超出允许范围(大于迷宫单元格数目或为负数)则输出字符串："Number out of range."。
	若网格无法连通，则输出字符串："Maze format error."。

文档结构：
	main.cpp:
		主程序，完成数据(两行字符串)的输入
	maze.h:
		maze类的数据成员以及成员函数的声明及定义；
		maze()构造函数，初始化为2*2的道路网格；
		setmazetext(int **matrix)根据道路网格矩阵来渲染字符串；
		creat(string &command)根据command字符串获取道路网格大小以及道路网格连通信息，新建描述道路网格的矩阵(1：道路0：墙)，调用setmazetext(int **matrix)来渲染字符串；
		getmazetext()返回渲染字符串。
