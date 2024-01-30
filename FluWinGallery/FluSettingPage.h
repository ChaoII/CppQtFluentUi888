#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>

#include "../FluUtils/FluUtils.h"
#include "../FluControls/FluVScrollView.h"
#include "../FluControls/FluSettingsSelectBox.h"
#include "../FluControls/FluSettingsLabelBox.h"

class FluSettingPage : public QWidget
{
	Q_OBJECT
  public:
	  FluSettingPage(QWidget* parent = nullptr) : QWidget(parent)
	  {
              m_mainLayout = new QVBoxLayout;
              m_mainLayout->setAlignment(Qt::AlignTop);
              setLayout(m_mainLayout);

              m_mainLayout->setContentsMargins(35, 35, 35, 35);

              m_titleLabel = new QLabel;
              m_titleLabel->setObjectName("titleLabel");
              m_titleLabel->setText("Settings");
              m_mainLayout->addWidget(m_titleLabel);

              m_vScrollView = new FluVScrollView;
              m_vScrollView->setObjectName("vScrollView");
              m_mainLayout->addWidget(m_vScrollView, 1);

              m_vScrollView->getMainLayout()->setAlignment(Qt::AlignTop);

              m_appBehaviorLabel = new QLabel;
              m_appBehaviorLabel->setObjectName("appBehaviorLabel");
              m_appBehaviorLabel->setText("Appearance & behavior");
              m_vScrollView->getMainLayout()->addWidget(m_appBehaviorLabel);

              auto appThemeSelectBox = new FluSettingsSelectBox;
              appThemeSelectBox->setTitleInfo("App theme", "Select which app theme to display.");
              appThemeSelectBox->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Color)); 

              appThemeSelectBox->getComboBox()->addItem("Light");
              appThemeSelectBox->getComboBox()->addItem("Dark");

              m_vScrollView->getMainLayout()->addWidget(appThemeSelectBox);


              auto navStyleSelectBox = new FluSettingsSelectBox;
              navStyleSelectBox->hideInfoLabel();
              navStyleSelectBox->setTitleInfo("Navigation style", "");
              navStyleSelectBox->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::HolePunchLandscapeLeft));
              navStyleSelectBox->getComboBox()->addItem("Left");
              navStyleSelectBox->getComboBox()->addItem("Top");
              m_vScrollView->getMainLayout()->addWidget(navStyleSelectBox);

              m_vScrollView->getMainLayout()->addSpacing(30);

              m_aboutLabel = new QLabel;
              m_aboutLabel->setObjectName("aboutLabel");
              m_aboutLabel->setText("About");
              m_vScrollView->getMainLayout()->addWidget(m_aboutLabel);

              auto aboutLabelBox = new FluSettingsLabelBox;
              aboutLabelBox->setTitleInfo("CppQtFluent888 Gallery", "^-^");
              aboutLabelBox->setIcon(QIcon("../res/Tiles/GalleryIcon.ico"));
              aboutLabelBox->setVersion("0.0.1");
              m_vScrollView->getMainLayout()->addWidget(aboutLabelBox);
              FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluSettingPage.qss", this);
	  }

	  void paintEvent(QPaintEvent* event)
	  {
              QStyleOption opt;
              opt.initFrom(this);
              QPainter painter(this);
              style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	  }

 protected:
          QVBoxLayout* m_mainLayout;

          QLabel* m_titleLabel;
          QLabel* m_appBehaviorLabel;
          QLabel* m_aboutLabel;
          FluVScrollView* m_vScrollView;
};