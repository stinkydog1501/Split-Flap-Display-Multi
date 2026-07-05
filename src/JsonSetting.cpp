#include "JsonSetting.h"

String JsonSetting::intVectorToString(const std::vector<int> &vec) {
    String result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += String(vec[i]);
        if (i < vec.size() - 1) {
            result += ",";
        }
    }
    return result;
}

String JsonSetting::intMatrixToString(const std::vector<std::vector<int>> &mat) {
    String result;
    for (size_t r = 0; r < mat.size(); ++r) {
        if (r > 0) result += ";";
        for (size_t c = 0; c < mat[r].size(); ++c) {
            result += String(mat[r][c]);
            if (c < mat[r].size() - 1) {
                result += ",";
            }
        }
    }
    return result;
}

bool JsonSetting::validate(String str) {
    switch (type) {
        case JsonSettingType::JST_INT_VECTOR: return validateIntVector(str);
        case JsonSettingType::JST_INT_MATRIX: return validateIntMatrix(str);
        default: return true;
    }
}

bool JsonSetting::validateIntVector(String str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ',' || str[i] == '-') {
            continue;
        }
        if (str[i] < '0' || str[i] > '9') {
            lastValidationError = "Non-integer value found";
            return false;
        }
    }
    return true;
}

bool JsonSetting::validateIntMatrix(String str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ',' || str[i] == ';' || str[i] == '-') {
            continue;
        }
        if (str[i] < '0' || str[i] > '9') {
            lastValidationError = "Non-integer value found in matrix";
            return false;
        }
    }
    return true;
}
