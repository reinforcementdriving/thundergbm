//
// Created by zeyi on 1/10/19.
//

#include "thundergbm/parser.h"
#include <thundergbm/dataset.h>
#include "thundergbm/predictor.h"
#ifdef _WIN32
    INITIALIZE_EASYLOGGINGPP
#endif
int main(int argc, char **argv) {
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime %level %fbase:%line : %msg");
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat);
    el::Loggers::reconfigureAllLoggers(el::Level::Debug, el::ConfigurationType::Enabled, "false");
    el::Loggers::reconfigureAllLoggers(el::Level::Trace, el::ConfigurationType::Enabled, "false");

    GBMParam model_param;
    Parser parser;
    parser.parse_param(model_param, argc, argv);

    //load data set
    DataSet dataSet;
    //load model
    vector<vector<Tree>> boosted_model;
    parser.load_model(model_param, boosted_model, dataSet);
    dataSet.load_from_file(model_param.path, model_param);


    //predict
    Predictor pred;
    vector<float_type> y_pred_vec = pred.predict(model_param, boosted_model, dataSet);

    //users can use y_pred_vec for their own purpose.
}
