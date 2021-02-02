#include "ADSOperationWidget.h"
#include "UIRoutines.h"

ADSOperationWidget::ADSOperationWidget(const QString& op, QWidget* parent) : QWidget(parent), slider(new QSlider(this)), layout(new QVBoxLayout(this)), name(op) {
	this->slider->setRange(0, 100);
	this->slider->setOrientation(Qt::Orientation::Horizontal);
	this->text.setText(QString(this->name + " [%1]").arg(this->slider->value()));
	layout->addWidget(&this->text);
	layout->addWidget(this->slider);
	this->layout->setMargin(0);

	this->text.setAlignment(Qt::AlignmentFlag::AlignCenter);

	QObject::connect(this->slider, &QSlider::valueChanged, this, &ADSOperationWidget::setValueText);
	QObject::connect(this->slider, &QSlider::valueChanged, this, &ADSOperationWidget::sliderValueChanged);
}

ADSOperationWidget::~ADSOperationWidget() {
	delete this->slider;
	this->slider = nullptr;
	delete this->layout;
	this->layout = nullptr;
}

int ADSOperationWidget::getValue() {
	return this->slider->value();
}

void ADSOperationWidget::setValueText(int n) {
	this->text.setText(QString(this->name + " [%1]").arg(n));
}
