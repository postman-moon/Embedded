#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::shapeChanged()
{
    int index = ui->cboShape->currentIndex();

    Shape shape = (Shape)ui->cboShape->itemData(index).toInt();

    ui->paintWidget->setShape(shape);
}

void Widget::penChanged()
{
    int width = ui->sbPenWidth->value();

    QPalette pal = ui->btnPenColor->palette();
    QColor color = pal.color(QPalette::Button);

    int styleIndex = ui->cboPenStyle->currentIndex();
    Qt::PenStyle style = (Qt::PenStyle)ui->cboPenStyle->itemData(styleIndex).toInt();

    int capIndex = ui->cboPenCap->currentIndex();
    Qt::PenCapStyle capStyle = (Qt::PenCapStyle)ui->cboPenCap->itemData(capIndex).toInt();

    int joinIndex = ui->cboPenJoin->currentIndex();
    Qt::PenJoinStyle joinStyle = (Qt::PenJoinStyle)ui->cboPenJoin->itemData(joinIndex).toInt();

    ui->paintWidget->setPen(QPen(color, width, style, capStyle, joinStyle));
}

void Widget::onBtnPenColorClicked()
{
    QColor color = QColorDialog::getColor(QColor(255, 0, 0), this, "画笔颜色");

    if (!color.isValid()) {
        return ;
    }

    QPalette pal = ui->btnPenColor->palette();
    pal.setColor(QPalette::Button, color);
    ui->btnPenColor->setPalette(pal);
    ui->btnPenColor->setAutoFillBackground(true);
    ui->btnPenColor->setFlat(true);

    penChanged();
}

void Widget::brushChanged()
{
    // 1. 获取画刷颜色
    QPalette pal = ui->btnBrushColor->palette();
    QColor col = pal.color(QPalette::Button);

    // 2. 获取画刷样式
    int styleIndex = ui->cboBrushStyle->currentIndex();
    Qt::BrushStyle style = (Qt::BrushStyle)ui->cboBrushStyle->itemData(styleIndex).toInt();

    // 3. 设置画刷
    if (style == Qt::LinearGradientPattern) {       // 线性渐变
        QLinearGradient linearGradient(0, 50, 100, 50);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, col);
        linearGradient.setColorAt(1.0, Qt::black);

        ui->paintWidget->setBrush(linearGradient);
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, col);
        radialGradient.setColorAt(1.0, Qt::black);

        ui->paintWidget->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, col);
        conicalGradient.setColorAt(1.0, Qt::black);

        ui->paintWidget->setBrush(conicalGradient);
    } else if (style == Qt::TexturePattern) {
        ui->paintWidget->setBrush(QBrush(QPixmap(":/images/brick.png")));
    } else {
        ui->paintWidget->setBrush(QBrush(col, style));
    }
}

void Widget::onBtnBrushColorClicked()
{
    QColor color = QColorDialog::getColor(QColor(255, 0, 0), this, "画刷颜色");

    if (!color.isValid())
        return;

    QPalette pal = ui->btnBrushColor->palette();
    pal.setColor(QPalette::Button, color);
    ui->btnBrushColor->setPalette(pal);
    ui->btnBrushColor->setAutoFillBackground(true);
    ui->btnBrushColor->setFlat(true);

    brushChanged();

}

void Widget::antialiasChanged()
{
    ui->paintWidget->setAntialias(ui->chkAntialiasing->isChecked());
}

void Widget::transformationChanged()
{
    ui->paintWidget->setTransformation(ui->chkTransformation->isChecked());
}

void Widget::initUI()
{
    // 1. 形状类型下拉框（cboShape）：添加支持的绘图形状选项
    ui->cboShape->addItem("Point", static_cast<int>(_Point));             // 点
    ui->cboShape->addItem("Line", static_cast<int>(_Line));               // 直线
    ui->cboShape->addItem("Rect", static_cast<int>(_Rect));               // 普通矩形
    ui->cboShape->addItem("RoundeRect", static_cast<int>(_RoundeRect));   // 圆角矩形
    ui->cboShape->addItem("Ellipse", static_cast<int>(_Ellipse));         // 椭圆/圆
    ui->cboShape->addItem("Arc", static_cast<int>(_Arc));                 // 圆弧
    ui->cboShape->addItem("Pie", static_cast<int>(_Pie));                 // 扇形（饼图）
    ui->cboShape->addItem("Chord", static_cast<int>(_Chord));             // 弦形
    ui->cboShape->addItem("Path", static_cast<int>(_Path));               // 自定义路径
    ui->cboShape->addItem("Text", static_cast<int>(_Text));               // 文本
    ui->cboShape->addItem("Pixmap", static_cast<int>(_Pixmap));           // 图片
    ui->cboShape->addItem("Polyline", static_cast<int>(_Polyline));
    ui->cboShape->addItem("Polygon", static_cast<int>(_Polygon));

    // 2. 画笔宽度控制（sbPenWidth）：设置允许的线宽范围为 1~10 像素
    ui->sbPenWidth->setRange(1, 10);

    // 3. 线型选择（cboPenStyle）：添加各种线型样式到下拉框中
    // 3.1 Qt::PenStyle 定义的各种线型 - enum Qt::PenStyle
    ui->cboPenStyle->addItem("SolidLine", static_cast<int>(Qt::SolidLine));           // 实线
    ui->cboPenStyle->addItem("DashLine", static_cast<int>(Qt::DashLine));             // 虚线（长划线）
    ui->cboPenStyle->addItem("DotLine", static_cast<int>(Qt::DotLine));               // 点线（短点）
    ui->cboPenStyle->addItem("DashDotLine", static_cast<int>(Qt::DashDotLine));       // 虚点线（长划线+点）
    ui->cboPenStyle->addItem("DashDotDotLine", static_cast<int>(Qt::DashDotDotLine)); // 更复杂的虚点线（划线+点+点）
    ui->cboPenStyle->addItem("CustomDashLine", static_cast<int>(Qt::CustomDashLine)); // 自定义虚线模式（需要设置 dashPattern）

    // 3.2 线端样式（Pen Cap Style）：决定线条终点的外观 - enum Qt::PenCapStyle
    ui->cboPenCap->addItem("SquareCap", static_cast<int>(Qt::SquareCap));  // 方形端点：线条稍稍超出终点，带一个方角
    ui->cboPenCap->addItem("FlatCap", static_cast<int>(Qt::FlatCap));      // 平端点：线条在终点截断（默认样式）
    ui->cboPenCap->addItem("RoundCap", static_cast<int>(Qt::RoundCap));    // 圆形端点：终点是半圆弧，更柔和的视觉效果

    // 3.3 线段连接样式（Pen Join Style）：决定线段相交处的连接方式（用于折线、矩形等）- enum Qt::PenJoinStyle
    ui->cboPenJoin->addItem("MiterJoin", static_cast<int>(Qt::MiterJoin));        // 尖角连接：默认连接方式，线角拉伸成尖角
    ui->cboPenJoin->addItem("BevelJoin", static_cast<int>(Qt::BevelJoin));        // 斜角连接：连接处截成斜角，防止过尖
    ui->cboPenJoin->addItem("RoundJoin", static_cast<int>(Qt::RoundJoin));        // 圆角连接：连接处绘制圆弧，视觉柔和
    ui->cboPenJoin->addItem("SvgMiterJoin", static_cast<int>(Qt::SvgMiterJoin));  // SVG 风格的尖角连接：类似 MiterJoin，但符合 SVG 规范

    // 4. 画刷样式：用于设置图形内部的填充效果 - enum Qt::BrushStyle
    ui->cboBrushStyle->addItem("NoBrush", static_cast<int>(Qt::NoBrush));  // 无填充（透明），只有轮廓
    ui->cboBrushStyle->addItem("SolidPattern", static_cast<int>(Qt::SolidPattern));  // 实心填充（纯色）

    // 密集图案填充（从 Dense1 到 Dense7，线条从稀到密）
    ui->cboBrushStyle->addItem("Dense1Pattern", static_cast<int>(Qt::Dense1Pattern));  // 最稀疏的斜线填充
    ui->cboBrushStyle->addItem("Dense2Pattern", static_cast<int>(Qt::Dense2Pattern));
    ui->cboBrushStyle->addItem("Dense3Pattern", static_cast<int>(Qt::Dense3Pattern));
    ui->cboBrushStyle->addItem("Dense4Pattern", static_cast<int>(Qt::Dense4Pattern));  // 中等密度
    ui->cboBrushStyle->addItem("Dense5Pattern", static_cast<int>(Qt::Dense5Pattern));
    ui->cboBrushStyle->addItem("Dense6Pattern", static_cast<int>(Qt::Dense6Pattern));
    ui->cboBrushStyle->addItem("Dense7Pattern", static_cast<int>(Qt::Dense7Pattern));  // 最密集的斜线填充

    // 水平、垂直、交叉线条图案
    ui->cboBrushStyle->addItem("HorPattern", static_cast<int>(Qt::HorPattern));        // 水平线条
    ui->cboBrushStyle->addItem("VerPattern", static_cast<int>(Qt::VerPattern));        // 垂直线条
    ui->cboBrushStyle->addItem("CrossPattern", static_cast<int>(Qt::CrossPattern));    // 十字交叉线条

    // 对角线图案
    ui->cboBrushStyle->addItem("BDiagPattern", static_cast<int>(Qt::BDiagPattern));     // 反斜线（\）
    ui->cboBrushStyle->addItem("FDiagPattern", static_cast<int>(Qt::FDiagPattern));     // 正斜线（/）
    ui->cboBrushStyle->addItem("DiagCrossPattern", static_cast<int>(Qt::DiagCrossPattern)); // 斜交叉（X 形）

    // 渐变图案（需要设置 QBrush 为渐变类型才有效）
    ui->cboBrushStyle->addItem("LinearGradientPattern", static_cast<int>(Qt::LinearGradientPattern));     // 线性渐变
    ui->cboBrushStyle->addItem("ConicalGradientPattern", static_cast<int>(Qt::ConicalGradientPattern));   // 圆锥渐变
    ui->cboBrushStyle->addItem("RadialGradientPattern", static_cast<int>(Qt::RadialGradientPattern));     // 放射渐变（圆形）

    // 纹理图案
    ui->cboBrushStyle->addItem("TexturePattern", static_cast<int>(Qt::TexturePattern)); // 图片纹理填充（需要配合 QPixmap 设置）


    // 5. 关联信号槽
    connect(ui->cboShape, SIGNAL(activated(QString)), this, SLOT(shapeChanged()));

    // 画笔设置
    // 画笔宽度
    connect(ui->sbPenWidth, SIGNAL(valueChanged(int)), this, SLOT(penChanged()));
    // 画笔颜色
    connect(ui->btnPenColor, SIGNAL(clicked()), this, SLOT(onBtnPenColorClicked()));
    // 画笔样式
    connect(ui->cboPenStyle, SIGNAL(activated(QString)), this, SLOT(penChanged()));
    // 画笔末端
    connect(ui->cboPenCap, SIGNAL(activated(QString)), this, SLOT(penChanged()));
    // 画笔连接
    connect(ui->cboPenJoin, SIGNAL(activated(QString)), this, SLOT(penChanged()));

    // 初始化
    // 把颜色回显到按钮上
    QPalette pal = ui->btnPenColor->palette();
    pal.setColor(QPalette::Button, QColor(255, 0, 0));
    ui->btnPenColor->setPalette(pal);
    ui->btnPenColor->setAutoFillBackground(true);
    ui->btnPenColor->setFlat(true);

    // 画刷设置
    // 画刷颜色
    connect(ui->btnBrushColor, SIGNAL(clicked()), this, SLOT(onBtnBrushColorClicked()));
    // 画刷样式
    connect(ui->cboBrushStyle, SIGNAL(activated(QString)), this, SLOT(brushChanged()));

    connect(ui->cboBrushStyle, SIGNAL(activated(QString)), this, SLOT(brushChanged()));

    // 抗锯齿
    connect(ui->chkAntialiasing, &QCheckBox::toggled, this, &Widget::antialiasChanged);
    // 变换
    connect(ui->chkTransformation, &QCheckBox::toggled, this, &Widget::transformationChanged);

    shapeChanged();
    penChanged();
    brushChanged();
}

