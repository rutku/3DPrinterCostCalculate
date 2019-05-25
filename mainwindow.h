#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class About;

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QGridLayout;
class QVBoxLayout;
class QLabel;
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QComboBox;
class QRadioButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rb_weight_clicked();
    void rb_lenght_clicked();
    void btn_calculate_clicked();
    void cmb_filamentTypeChanged();


private:
    void createMenu();
    void printerInformation();
    void electricInformation();
    void filamentInformation();
    void workerInformation();
    void printingInformation();
    void calculateInformation();
    void resultInformation();
    void setup();
    void loadSettings();
    void saveSettings();
    void aboutClicked();

    About *aboutWindow;

    QString settingsFile;

    QGridLayout *mainLayout;

    //Printer Information
    QGridLayout *printerLayout;
    QLabel *lbl_printerCost;
    QLabel *lbl_printerLife;

    QDoubleSpinBox *spn_printerCost;
    QSpinBox *spn_printerLife;

    //Electric Information
    QGridLayout *electricLayout;
    QLabel *lbl_printerElectricityUsage;
    QLabel *lbl_electricityUsageFee;
    QDoubleSpinBox *spn_printerElectricityUsage;
    QDoubleSpinBox *spn_electricityUsageFee;

    //Filament Information
    QGridLayout *filamentLayout;
    QLabel *lbl_filamentType;
    QLabel *lbl_diameterOfFilament;
    QLabel *lbl_filamentDensity;
    QLabel *lbl_selectedFilamentDensity;
    QLabel *lbl_filamentWeight;
    QLabel *lbl_filamentFee;

    QComboBox *cmb_diameterOfFilament;
    QComboBox *cmb_filamentType;
    QDoubleSpinBox *spn_filamentWeight;
    QDoubleSpinBox *spn_filamentFee;

    //Worker Information
    QGridLayout *workerLayout;
    QLabel *lbl_workerHourlyRate;
    QDoubleSpinBox *spn_workerHourlyRate;

    //Printing Information
    QGridLayout *printingLayout;
    QGroupBox *box_weightOrLength;
    QRadioButton *rb_weight;
    QRadioButton *rb_lenght;
    QLabel *lbl_printingTime;
    QSpinBox *spn_printingTime;
    QDoubleSpinBox *spn_printingWeight;
    QSpinBox *spn_printingLenght;


    //Calculate
    QGridLayout *calculateLayout;
    QPushButton *btn_calculate;

    //Result
    QGridLayout *resultLayout;
    QTextEdit *txt_result;


    QMenuBar *menuBar;
    QGroupBox *printerInformationGridGroupBox;
    QGroupBox *electricInformationGridGroupBox;
    QGroupBox *workerInformaitonGridGroupBox;
    QGroupBox *filamentInformationGridGroupBox;
    QGroupBox *printingInformationGridGroupBox;
    QGroupBox *calculateGroupBox;
    QGroupBox *resultGroupBox;

    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *exitAction;
    QAction *act_about;
    QAction *act_qtAbout;

    //Filaments
    QStringList filamentTypeList;
    QStringList diameterOfFilamentList;
    QStringList filamentDensityList;


};

#endif // MAINWINDOW_H
