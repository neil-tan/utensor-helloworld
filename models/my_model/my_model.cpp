/* Auto-generated by utensor cli */
#include "uTensor.h"
#include "models/my_model/my_model.hpp"
#include "constants/my_model/params_my_model.hpp"


using namespace uTensor;

void compute_my_model(Tensor& t_input_10, Tensor& t_Identity0){
    // start rendering local snippets
    MaxPoolOperator<int8_t> op_000({ 2, 2 }, { 1, 2, 2, 1 }, VALID);


    TFLM::QuantizeOperator<int8_t, float> op_001;


    ReshapeOperator<int8_t> op_002({ 1, 288 });


    QuantizedDepthwiseSeparableConvOperator<int8_t> op_003({ 1, 1 }, VALID, 8, { 1, 1 }, TFLM::TfLiteFusedActivation::kTfLiteActRelu);


    QuantizedFullyConnectedOperator<int8_t> op_004(TFLM::TfLiteFusedActivation::kTfLiteActRelu);


    TFLM::DequantizeOperator<float, int8_t> op_005;


    QuantizedFullyConnectedOperator<int8_t> op_006(TFLM::TfLiteFusedActivation::kTfLiteActNone);


    Tensor t_input_1_int80 = new RamTensor({ 1, 28, 28, 1 }, i8);
    int32_t t_input_1_int80_zp = -128;
    float t_input_1_int80_scale = 0.003921569;
    PerTensorQuantizationParams t_input_1_int80_quant_params(t_input_1_int80_zp, t_input_1_int80_scale);
    t_input_1_int80->set_quantization_params(t_input_1_int80_quant_params);


    op_001
    .set_inputs({
        { TFLM::QuantizeOperator<int8_t, float>::input, t_input_10 },
    })
    .set_outputs({
        { TFLM::QuantizeOperator<int8_t, float>::output, t_input_1_int80}
    })
    .eval();

    Tensor t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0 = new RamTensor({ 1, 14, 14, 1 }, i8);
    int32_t t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_zp = -128;
    float t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_scale = 0.003921569;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_quant_params(t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_zp, t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_scale);
    t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0->set_quantization_params(t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0_quant_params);


    op_000
    .set_inputs({
        { MaxPoolOperator<int8_t>::in, t_input_1_int80 },
    })
    .set_outputs({
        { MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0}
    })
    .eval();

    t_input_1_int80.free();

    Tensor t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0 = new RomTensor({ 1, 3, 3, 8 }, i8, data_StatefulPartitionedCall_my_model_conv2d_Conv2D_ReadVariableOp_0);
    int32_t arr_t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_zp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_scale[8] = { 0.00833097, 0.010789413, 0.010345756, 0.006805609, 0.0060893036, 0.0080149155, 0.007064641, 0.009796781 };
    PerChannelQuantizationParams t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_quant_params(arr_t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_zp, arr_t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_scale);
    t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0->set_quantization_params(t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0_quant_params);


    Tensor t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0 = new RomTensor({ 8 }, i32, data_StatefulPartitionedCall_my_model_conv2d_Conv2D_bias_0);
    int32_t arr_t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_zp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_scale[8] = { 3.2670472e-05, 4.2311425e-05, 4.0571595e-05, 2.6688664e-05, 2.3879624e-05, 3.1431042e-05, 2.7704476e-05, 3.841875e-05 };
    PerChannelQuantizationParams t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_quant_params(arr_t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_zp, arr_t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_scale);
    t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0->set_quantization_params(t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0_quant_params);


    Tensor t_StatefulPartitionedCallmy_modelconv2dRelu0 = new RamTensor({ 1, 12, 12, 8 }, i8);
    int32_t t_StatefulPartitionedCallmy_modelconv2dRelu0_zp = -128;
    float t_StatefulPartitionedCallmy_modelconv2dRelu0_scale = 0.009453258;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modelconv2dRelu0_quant_params(t_StatefulPartitionedCallmy_modelconv2dRelu0_zp, t_StatefulPartitionedCallmy_modelconv2dRelu0_scale);
    t_StatefulPartitionedCallmy_modelconv2dRelu0->set_quantization_params(t_StatefulPartitionedCallmy_modelconv2dRelu0_quant_params);


    op_003
    .set_inputs({
        { QuantizedDepthwiseSeparableConvOperator<int8_t>::in, t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0 },
        { QuantizedDepthwiseSeparableConvOperator<int8_t>::filter, t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0 },
        { QuantizedDepthwiseSeparableConvOperator<int8_t>::bias, t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0 },
    })
    .set_outputs({
        { QuantizedDepthwiseSeparableConvOperator<int8_t>::out, t_StatefulPartitionedCallmy_modelconv2dRelu0}
    })
    .eval();

    t_StatefulPartitionedCallmy_modelconv2dConv2D_bias0.free();

    t_StatefulPartitionedCallmy_modelconv2dConv2DReadVariableOp0.free();

    t_StatefulPartitionedCallmy_modelmax_pooling2dMaxPool0.free();

    Tensor t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0 = new RamTensor({ 1, 6, 6, 8 }, i8);
    int32_t t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_zp = -128;
    float t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_scale = 0.009453258;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_quant_params(t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_zp, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_scale);
    t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0->set_quantization_params(t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0_quant_params);


    op_000
    .set_inputs({
        { MaxPoolOperator<int8_t>::in, t_StatefulPartitionedCallmy_modelconv2dRelu0 },
    })
    .set_outputs({
        { MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0}
    })
    .eval();

    t_StatefulPartitionedCallmy_modelconv2dRelu0.free();

    Tensor t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00 = new RamTensor({ 1, 288 }, i8);
    int32_t t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_zp = -128;
    float t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_scale = 0.009453258;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_quant_params(t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_zp, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_scale);
    t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00->set_quantization_params(t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00_quant_params);


    op_002
    .set_inputs({
        { ReshapeOperator<int8_t>::input, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0 },
    })
    .set_outputs({
        { ReshapeOperator<int8_t>::output, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00}
    })
    .eval();

    t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool0.free();

    Tensor t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0 = new RomTensor({ 288, 16 }, i8, data_StatefulPartitionedCall_my_model_dense_MatMul_ReadVariableOp_transpose_0);
    int32_t t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_zp = 0;
    float t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_scale = 0.0099207945;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_quant_params(t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_zp, t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_scale);
    t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0->set_quantization_params(t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0_quant_params);


    Tensor t_StatefulPartitionedCallmy_modeldenseMatMul_bias0 = new RomTensor({ 16 }, i32, data_StatefulPartitionedCall_my_model_dense_MatMul_bias_0);
    int32_t t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_zp = 0;
    float t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_scale = 9.378383e-05;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_quant_params(t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_zp, t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_scale);
    t_StatefulPartitionedCallmy_modeldenseMatMul_bias0->set_quantization_params(t_StatefulPartitionedCallmy_modeldenseMatMul_bias0_quant_params);


    Tensor t_StatefulPartitionedCallmy_modeldenseRelu0 = new RamTensor({ 1, 16 }, i8);
    int32_t t_StatefulPartitionedCallmy_modeldenseRelu0_zp = -128;
    float t_StatefulPartitionedCallmy_modeldenseRelu0_scale = 0.069232814;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modeldenseRelu0_quant_params(t_StatefulPartitionedCallmy_modeldenseRelu0_zp, t_StatefulPartitionedCallmy_modeldenseRelu0_scale);
    t_StatefulPartitionedCallmy_modeldenseRelu0->set_quantization_params(t_StatefulPartitionedCallmy_modeldenseRelu0_quant_params);


    op_004
    .set_inputs({
        { QuantizedFullyConnectedOperator<int8_t>::input, t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00 },
        { QuantizedFullyConnectedOperator<int8_t>::filter, t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0 },
        { QuantizedFullyConnectedOperator<int8_t>::bias, t_StatefulPartitionedCallmy_modeldenseMatMul_bias0 },
    })
    .set_outputs({
        { QuantizedFullyConnectedOperator<int8_t>::output, t_StatefulPartitionedCallmy_modeldenseRelu0}
    })
    .eval();

    t_StatefulPartitionedCallmy_modeldenseMatMul_bias0.free();

    t_StatefulPartitionedCallmy_modeldenseMatMulReadVariableOptranspose0.free();

    t_StatefulPartitionedCallmy_modelmax_pooling2d_1MaxPool_0_Reshape00.free();

    Tensor t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0 = new RomTensor({ 16, 10 }, i8, data_StatefulPartitionedCall_my_model_dense_1_MatMul_ReadVariableOp_transpose_0);
    int32_t t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_zp = 0;
    float t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_scale = 0.010994066;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_quant_params(t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_zp, t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_scale);
    t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0->set_quantization_params(t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0_quant_params);


    Tensor t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0 = new RomTensor({ 10 }, i32, data_StatefulPartitionedCall_my_model_dense_1_MatMul_bias_0);
    int32_t t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_zp = 0;
    float t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_scale = 0.0007611501;
    PerTensorQuantizationParams t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_quant_params(t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_zp, t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_scale);
    t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0->set_quantization_params(t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0_quant_params);


    Tensor t_Identity_int80 = new RamTensor({ 1, 10 }, i8);
    int32_t t_Identity_int80_zp = 30;
    float t_Identity_int80_scale = 0.17807707;
    PerTensorQuantizationParams t_Identity_int80_quant_params(t_Identity_int80_zp, t_Identity_int80_scale);
    t_Identity_int80->set_quantization_params(t_Identity_int80_quant_params);


    op_006
    .set_inputs({
        { QuantizedFullyConnectedOperator<int8_t>::input, t_StatefulPartitionedCallmy_modeldenseRelu0 },
        { QuantizedFullyConnectedOperator<int8_t>::filter, t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0 },
        { QuantizedFullyConnectedOperator<int8_t>::bias, t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0 },
    })
    .set_outputs({
        { QuantizedFullyConnectedOperator<int8_t>::output, t_Identity_int80}
    })
    .eval();

    t_StatefulPartitionedCallmy_modeldense_1MatMul_bias0.free();

    t_StatefulPartitionedCallmy_modeldense_1MatMulReadVariableOptranspose0.free();

    t_StatefulPartitionedCallmy_modeldenseRelu0.free();

    op_005
    .set_inputs({
        { TFLM::DequantizeOperator<float, int8_t>::a, t_Identity_int80 },
    })
    .set_outputs({
        { TFLM::DequantizeOperator<float, int8_t>::b, t_Identity0}
    })
    .eval();

    t_Identity_int80.free();
    // end of rendering local snippets
}