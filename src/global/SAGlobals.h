﻿#ifndef SAGLOBALS_H
#define SAGLOBALS_H
class SAAbstractDatas;
#include <QScopedPointer>
///
/// \def 包含Ribbon界面
///
#ifndef SA_USE_RIBBON_UI
#define SA_USE_RIBBON_UI 1
#endif
///
/// \def 前置声明的定义
///
#ifndef SA_IMPL_FORWARD_DECL
#define SA_IMPL_FORWARD_DECL(ClassName) \
    class ClassName##Private;
#endif
///
/// \def impl的简易实现
///
#ifndef SA_IMPL
#define SA_IMPL(Class) \
    private:\
    inline Class##Private* d_func() { return d_ptr.data(); } \
    inline const Class##Private* d_func() const { return d_ptr.data(); } \
    friend class Class##Private;\
    QScopedPointer< Class##Private > d_ptr;
#endif
///
/// \def impl的定义
///
#ifndef SA_IMPL_PUBLIC
#define SA_IMPL_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;\
    Class* q_ptr;
#endif
///
/// \def impl获取指针，参考Q_D
///
#ifndef SA_D
#define SA_D(Class) \
    Class##Private * d = d_func()
#endif
///
/// \def impl获取指针，参考Q_D
///
#ifndef SA_DC
#define SA_DC(Class) \
    const Class##Private * d = d_func()
#endif
///
/// \def impl获取指针，参考Q_Q
///
#ifndef SA_Q
#define SA_Q(Class) \
    Class * q = q_func()
#endif
///
/// \def impl获取指针，参考Q_Q
///
#ifndef SA_QC
#define SA_QC(Class) \
    const Class * q = q_func()
#endif



namespace SA {
//    enum ThermoChartPARAM{
//        T//< 温度
//        ,P///< 压力
//        ,S///< 熵
//        ,H///< 焓
//    };
//    enum ThermoChartMODE{
//        TS
//        ,HS
//        ,PT
//    };

    enum DataSelectRange{
        InSelectionRange = 0x1///<在可视范围内
        ,OutSelectionRange = 0x2///< 不可视范围内
        ,AllRange = 0x3///< 所有范围
    };
    ///
    /// \brief 导出数据时的模式
    ///
    enum PickDataMode
    {
        XOnly///< 只导出x值，这样导出的数据为DataMode::DoubleSeries
        ,YOnly///< 只导出y值，这样导出的数据为DataMode::DoubleSeries
        ,XYPoint///< 导出xy值，这样导出的数据为DataMode::PointSeries
    };


    ///
    /// \brief 此类型用于标定一个mdi子窗口的属性，属于哪一类型的窗口，在mdi子窗口创建时设定在MdiSubWindow里，
    /// \see MdiSubWindow::setType
    ///
    enum SubWndType{
        SubWindowFigure///< Figure窗口
        ,SubWindowUserDefine///< 用户自定义图
    };

    enum ProjectTreeMark
    {
        MARK_NONE = 0
        ,MARK_PROJECT = 0x80000000
        ,MARK_FOLDER = 0x40000000
        ,MARK_ITEM = 0x20000000
    };
    ///
    /// \brief 全局定义的信息类型，sa中有些类会发射错误或者一些提示信息，
    /// 一般为messageInformation信号，此信号的第二个参数为信息的分类
    /// 此枚举主要对这些信息进行分类
    ///
    enum MeaasgeType{
        NormalMessage = 0///< 普通消息
        ,WarningMessage///< 警告的消息
        ,ErrorMessage///< 出错的消息
        ,QuesstionMessage///< 疑问信息
    };

    ///
    /// \brief The DataType enum
    ///
    enum DataType
    {
        UnknowType = -1///< 不知类型
        ,DataLink = -2///<数据的连接类型

        ,CanBeDrawBoundaryDataTypeStart = 0///<可绘制范围 - start

        ,Variant = 1///< 基本类型


        ,VectorDouble=100///< 数组
        ,VectorPoint=200///< 点数组
        ,VectorInt=300///< 数组
        ,VectorVariant=400///< 数组
        ,VectorInterval=500///< (value,min,max)数组
        ,VectorOHLC=510///< 股票金融数据Open heigh low close

        ,TableBoundaryBegin = 1000///< 表格开始范围
        ,TableVariant = 1001///< 任意类型表格
        ,TableDouble = 1002///< 数值表格
        ,TableBoundaryEnd = 2000///< 表格结束范围

        ,TdmsChannel = 2100///< tdms通道
        ,CanBeDrawBoundaryDataTypeEnd = 9000///<可绘制范围 - end

        ,FolderBoundaryBegin = 9100///<文件夹性质数据类型开始
        ,TdmsFile = 9105///< tdms文件
        ,TdmsGroup = 9106///< tdms组
        ,FolderBoundaryEnd = 9900///<文件夹性质数据类型结束
    };

    enum DataPackageType
    {
        DataPackageTypeStart = 1000000
        ,NormalDataPackage = 1000010 ///< 普通数据包
        ,DataPackageTypeEnd = 2000000
    };

//    enum FunType
//    {
//        FunctionBoundaryDataTypeStart = 10000///< 函数类型
//        ,FunctionFFt = 10010 ///< 傅里叶变换函数
//        ,FunctionPolyfit = 10020 ///<多项式拟合函数
//        ,FunctionFilter = 10030 ///<滤波函数
//        ,FunctionStatistics = 10040 ///<统计学相关函数
//        ,FunctionNum = 10050///< 数值计算相关函数
//        ,FunctionBoundaryDataTypeEnd = 90000///< 函数类型结束
//    };

    enum SizeType{
        Row=1
        ,Column=2
    };
    enum DimType{
        Dim0=0
        ,Dim1=1
        ,Dim2=2
        ,Dim3=3
    };



}

#define ROLE_ITEM_MARK Qt::UserRole + 1///< 标志角色
#define ROLE_ITEM_WIDGET Qt::UserRole + 10///< 关联窗口角色
#define ROLE_FOLDER_MARK Qt::UserRole + 20 ///< 文件夹标记
#define ROLE_DATATYPE_MARK Qt::UserRole + 30 ///< 数据标记,所有需要绘制的条目都需要设置这个ROLE_DATATYPE_MARK，用于标定DATAMODE \see DATAMODE
#define ROLE_ID Qt::UserRole + 40 ///< 数据标记

//#define MARK_PROJECT 0x80000000 ///< 顶层项目标记位
//#define MARK_FOLDER 0x40000000 ///< 文件夹标记位
//#define MARK_ITEM 0x20000000 ///< 项目标记位

//#define MARK_PROJECT_ID_BIT 0xFF ///< 顶层项目个数存放位置，MARK与此位&（于）操作后，即可提取该条目或文件夹所属的项目,因此项目的最大数目为0xFF

#define ICON_Project QIcon(":/treeItemIcon/res_treeItemIcon/Project.png")
#define ICON_folder QIcon(":/treeItemIcon/res_treeItemIcon/folder.png")
#define ICON_FolderUserChart QIcon(":/treeItemIcon/res_treeItemIcon/folder-ansys.png")
#define ICON_TdmsGroup QIcon(":/treeItemIcon/res_treeItemIcon/group.png")

#define ICON_folderOriginal QIcon(":/treeItemIcon/res_treeItemIcon/folder_original.png")
#define ICON_DataItem QIcon(":/treeItemIcon/res_treeItemIcon/dataItem.png")




#define ICON_CountFrequency  QIcon(":/image/res_image/count_frequency.png")
#define ICON_TdmsChannel QIcon(":/treeItemIcon/res_treeItemIcon/channel.png")
#define ICON_ItemDouble QIcon(":/treeItemIcon/res_treeItemIcon/doubles.png")
#define ICON_ItemPoint QIcon(":/treeItemIcon/res_treeItemIcon/points.png")

#define SA_MIME_ProjectItem "sa/projectItem"
#define SA_MIME_ValueManagerItem "sa/ValueManagerItem"



#ifndef SA_ROLE_DATA_TYPE
#define SA_ROLE_DATA_TYPE (Qt::UserRole + 1299)
#endif
#ifndef SA_ROLE_DATA_ID
#define SA_ROLE_DATA_ID (Qt::UserRole + 1099)
#endif


#ifndef SA_SIZE_TYPE_ROW
#define SA_SIZE_TYPE_ROW 1
#endif
#ifndef SA_SIZE_TYPE_COLUMN
#define SA_SIZE_TYPE_COLUMN 2
#endif

#ifndef SA_TYPE_FOLDER
#define SA_TYPE_FOLDER -1000
#endif

#endif // GLOBALS_H
