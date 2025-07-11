#include <vector>
#include <string>

#include "SMBusTypes.h"
#include "SMBusCommands.h"

// appendix 1 PMBus specs

const CommandDesc pmbus_cmds[] = {
    { 0x00, "PAGE", 1, ReadWrite, FT_Undefined },
    { 0x01, "OPERATION", 1, ReadWrite, FT_PMBusOperation },
    { 0x02, "ON_OFF_CONFIG", 1, ReadWrite, FT_PMBusOnOffConfig },
    { 0x03, "CLEAR_FAULTS", 0, Send, FT_Undefined },
    { 0x04, "PHASE", 1, ReadWrite, FT_Undefined },
    { 0x05, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x06, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x07, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x08, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x09, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0A, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0B, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0C, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0D, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0E, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x0F, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x10, "WRITE_PROTECT", 1, ReadWrite, FT_PMBusWriteProtect },
    { 0x11, "STORE_DEFAULT_ALL", 0, Send, FT_Undefined },
    { 0x12, "RESTORE_DEFAULT_ALL", 0, Send, FT_Undefined },
    { 0x13, "STORE_DEFAULT_CODE", 1, Write, FT_Undefined },
    { 0x14, "RESTORE_DEFAULT_CODE", 1, Write, FT_Undefined },
    { 0x15, "STORE_USER_ALL", 0, Send, FT_Undefined },
    { 0x16, "RESTORE_USER_ALL", 0, Send, FT_Undefined },
    { 0x17, "STORE_USER_CODE", 1, Write, FT_Undefined },
    { 0x18, "RESTORE_USER_CODE", 1, Write, FT_Undefined },
    { 0x19, "CAPABILITY", 1, Read, FT_PMBusCapability },
    // Block Write-Block Read-Process call  See Section 11.13
    { 0x1A, "QUERY", Undefined, Undefined, FT_Undefined },
    { 0x1B, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x1C, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x1D, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x1E, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x1F, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x20, "VOUT_MODE", 1, ReadWrite, FT_PMBusVoutMode },
    { 0x21, "VOUT_COMMAND", 2, ReadWrite, FT_Undefined },
    { 0x22, "VOUT_TRIM", 2, ReadWrite, FT_Undefined },
    { 0x23, "VOUT_CAL_OFFSET", 2, ReadWrite, FT_Undefined },
    { 0x24, "VOUT_MAX", 2, ReadWrite, FT_Undefined },
    { 0x25, "VOUT_MARGIN_HIGH", 2, ReadWrite, FT_Undefined },
    { 0x26, "VOUT_MARGIN_LOW", 2, ReadWrite, FT_Undefined },
    { 0x27, "VOUT_TRANSITION_RATE", 2, ReadWrite, FT_Undefined },
    { 0x28, "VOUT_DROOP", 2, ReadWrite, FT_Undefined },
    { 0x29, "VOUT_SCALE_LOOP", 2, ReadWrite, FT_Undefined },
    { 0x2A, "VOUT_SCALE_MONITOR", 2, ReadWrite, FT_Undefined },
    { 0x2B, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x2C, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x2D, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x2E, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x2F, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x30, "COEFFICIENTS", Undefined, Undefined, FT_Undefined },
    { 0x31, "POUT_MAX", 2, ReadWrite, FT_Undefined },
    { 0x32, "MAX_DUTY", 2, ReadWrite, FT_Undefined },
    { 0x33, "FREQUENCY_SWITCH", 2, ReadWrite, FT_Undefined },
    { 0x34, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x35, "VIN_ON", 2, ReadWrite, FT_Undefined },
    { 0x36, "VIN_OFF", 2, ReadWrite, FT_Undefined },
    { 0x37, "INTERLEAVE", 2, ReadWrite, FT_Undefined },
    { 0x38, "IOUT_CAL_GAIN", 2, ReadWrite, FT_Undefined },
    { 0x39, "IOUT_CAL_OFFSET", 2, ReadWrite, FT_Undefined },
    { 0x3A, "FAN_CONFIG_1_2", 1, ReadWrite, FT_Undefined },
    { 0x3B, "FAN_COMMAND_1", 2, ReadWrite, FT_Undefined },
    { 0x3C, "FAN_COMMAND_2", 2, ReadWrite, FT_Undefined },
    { 0x3D, "FAN_CONFIG_3_4", 1, ReadWrite, FT_Undefined },
    { 0x3E, "FAN_COMMAND_3", 2, ReadWrite, FT_Undefined },
    { 0x3F, "FAN_COMMAND_4", 2, ReadWrite, FT_Undefined },
    { 0x40, "VOUT_OV_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x41, "VOUT_OV_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x42, "VOUT_OV_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x43, "VOUT_UV_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x44, "VOUT_UV_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x45, "VOUT_UV_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x46, "IOUT_OC_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x47, "IOUT_OC_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x48, "IOUT_OC_LV_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x49, "IOUT_OC_LV_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x4A, "IOUT_OC_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x4B, "IOUT_UC_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x4C, "IOUT_UC_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x4D, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x4E, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x4F, "OT_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x50, "OT_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x51, "OT_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x52, "UT_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x53, "UT_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x54, "UT_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x55, "VIN_OV_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x56, "VIN_OV_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x57, "VIN_OV_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x58, "VIN_UV_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x59, "VIN_UV_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x5A, "VIN_UV_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x5B, "IIN_OC_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x5C, "IIN_OC_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x5D, "IIN_OC_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x5E, "POWER_GOOD_ON", 2, ReadWrite, FT_Undefined },
    { 0x5F, "POWER_GOOD_OFF", 2, ReadWrite, FT_Undefined },
    { 0x60, "TON_DELAY", 2, ReadWrite, FT_Undefined },
    { 0x61, "TON_RISE", 2, ReadWrite, FT_Undefined },
    { 0x62, "TON_MAX_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x63, "TON_MAX_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x64, "TOFF_DELAY", 2, ReadWrite, FT_Undefined },
    { 0x65, "TOFF_FALL", 2, ReadWrite, FT_Undefined },
    { 0x66, "TOFF_MAX_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x67, "Reserved", Undefined, Undefined, FT_Undefined }, // (Was Used In Revision 1.0)
    { 0x68, "POUT_OP_FAULT_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x69, "POUT_OP_FAULT_RESPONSE", 1, ReadWrite, FT_Undefined },
    { 0x6A, "POUT_OP_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x6B, "PIN_OP_WARN_LIMIT", 2, ReadWrite, FT_Undefined },
    { 0x6C, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x6D, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x6E, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x6F, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x70, "Reserved (Test Input Fuse A)", Undefined, Undefined, FT_Undefined },
    { 0x71, "Reserved (Test Input Fuse B)", Undefined, Undefined, FT_Undefined },
    { 0x72, "Reserved (Test Input OR-ing A)", Undefined, Undefined, FT_Undefined },
    { 0x73, "Reserved (Test Input OR-ing B)", Undefined, Undefined, FT_Undefined },
    { 0x74, "Reserved (Test Output OR-ing)", Undefined, Undefined, FT_Undefined },
    { 0x75, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x76, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x77, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x78, "STATUS_BYTE", 1, Read, FT_Undefined },
    { 0x79, "STATUS_WORD", 2, Read, FT_Undefined },
    { 0x7A, "STATUS_VOUT", 1, Read, FT_Undefined },
    { 0x7B, "STATUS_IOUT", 1, Read, FT_Undefined },
    { 0x7C, "STATUS_INPUT", 1, Read, FT_Undefined },
    { 0x7D, "STATUS_TEMPERATURE", 1, Read, FT_Undefined },
    { 0x7E, "STATUS_CML", 1, Read, FT_Undefined },
    { 0x7F, "STATUS_OTHER", 1, Read, FT_Undefined },
    { 0x80, "STATUS_MFR_SPECIFIC", 1, Read, FT_Undefined },
    { 0x81, "STATUS_FANS_1_2", 1, Read, FT_Undefined },
    { 0x82, "STATUS_FANS_3_4", 1, Read, FT_Undefined },
    { 0x83, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x84, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x85, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x86, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x87, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0x88, "READ_VIN", 2, Read, FT_Undefined },
    { 0x89, "READ_IIN", 2, Read, FT_Undefined },
    { 0x8A, "READ_VCAP", 2, Read, FT_Undefined },
    { 0x8B, "READ_VOUT", 2, Read, FT_Undefined },
    { 0x8C, "READ_IOUT", 2, Read, FT_Undefined },
    { 0x8D, "READ_TEMPERATURE_1", 2, Read, FT_Undefined },
    { 0x8E, "READ_TEMPERATURE_2", 2, Read, FT_Undefined },
    { 0x8F, "READ_TEMPERATURE_3", 2, Read, FT_Undefined },
    { 0x90, "READ_FAN_SPEED_1", 2, Read, FT_Undefined },
    { 0x91, "READ_FAN_SPEED_2", 2, Read, FT_Undefined },
    { 0x92, "READ_FAN_SPEED_3", 2, Read, FT_Undefined },
    { 0x93, "READ_FAN_SPEED_4", 2, Read, FT_Undefined },
    { 0x94, "READ_DUTY_CYCLE", 2, Read, FT_Undefined },
    { 0x95, "READ_FREQUENCY", 2, Read, FT_Undefined },
    { 0x96, "READ_POUT", 2, Read, FT_Undefined },
    { 0x97, "READ_PIN", 2, Read, FT_Undefined },
    { 0x98, "PMBUS_REVISION", 1, Read, FT_Undefined },
    { 0x99, "MFR_ID", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9A, "MFR_MODEL", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9B, "MFR_REVISION", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9C, "MFR_LOCATION", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9D, "MFR_DATE", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9E, "MFR_SERIAL", LengthVariable, ReadWrite, FT_Undefined },
    { 0x9F, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xA0, "MFR_VIN_MIN", 2, Read, FT_Undefined },
    { 0xA1, "MFR_VIN_MAX", 2, Read, FT_Undefined },
    { 0xA2, "MFR_IIN_MAX", 2, Read, FT_Undefined },
    { 0xA3, "MFR_PIN_MAX", 2, Read, FT_Undefined },
    { 0xA4, "MFR_VOUT_MIN", 2, Read, FT_Undefined },
    { 0xA5, "MFR_VOUT_MAX", 2, Read, FT_Undefined },
    { 0xA6, "MFR_IOUT_MAX", 2, Read, FT_Undefined },
    { 0xA7, "MFR_POUT_MAX", 2, Read, FT_Undefined },
    { 0xA8, "MFR_TAMBIENT_MAX", 2, Read, FT_Undefined },
    { 0xA9, "MFR_TAMBIENT_MIN", 2, Read, FT_Undefined },
    { 0xAA, "MFR_EFFICIENCY_LL", 14, ReadWrite, FT_Undefined },
    { 0xAB, "MFR_EFFICIENCY_HL", 14, ReadWrite, FT_Undefined },
    { 0xAC, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xAD, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xAE, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xAF, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xB0, "USER_DATA_00", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB1, "USER_DATA_01", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB2, "USER_DATA_02", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB3, "USER_DATA_03", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB4, "USER_DATA_04", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB5, "USER_DATA_05", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB6, "USER_DATA_06", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB7, "USER_DATA_07", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB8, "USER_DATA_08", LengthVariable, ReadWrite, FT_Undefined },
    { 0xB9, "USER_DATA_09", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBA, "USER_DATA_10", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBB, "USER_DATA_11", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBC, "USER_DATA_12", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBD, "USER_DATA_13", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBE, "USER_DATA_14", LengthVariable, ReadWrite, FT_Undefined },
    { 0xBF, "USER_DATA_15", LengthVariable, ReadWrite, FT_Undefined },
    { 0xC0, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC1, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC2, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC3, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC4, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC5, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC6, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC7, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC8, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xC9, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCA, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCB, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCC, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCD, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCE, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xCF, "Reserved", Undefined, Undefined, FT_Undefined },
    { 0xD0, "MFR_SPECIFIC_00", Undefined, Undefined, FT_Undefined },
    { 0xD1, "MFR_SPECIFIC_01", Undefined, Undefined, FT_Undefined },
    { 0xD2, "MFR_SPECIFIC_02", Undefined, Undefined, FT_Undefined },
    { 0xD3, "MFR_SPECIFIC_03", Undefined, Undefined, FT_Undefined },
    { 0xD4, "MFR_SPECIFIC_04", Undefined, Undefined, FT_Undefined },
    { 0xD5, "MFR_SPECIFIC_05", Undefined, Undefined, FT_Undefined },
    { 0xD6, "MFR_SPECIFIC_06", Undefined, Undefined, FT_Undefined },
    { 0xD7, "MFR_SPECIFIC_07", Undefined, Undefined, FT_Undefined },
    { 0xD8, "MFR_SPECIFIC_08", Undefined, Undefined, FT_Undefined },
    { 0xD9, "MFR_SPECIFIC_09", Undefined, Undefined, FT_Undefined },
    { 0xDA, "MFR_SPECIFIC_10", Undefined, Undefined, FT_Undefined },
    { 0xDB, "MFR_SPECIFIC_11", Undefined, Undefined, FT_Undefined },
    { 0xDC, "MFR_SPECIFIC_12", Undefined, Undefined, FT_Undefined },
    { 0xDD, "MFR_SPECIFIC_13", Undefined, Undefined, FT_Undefined },
    { 0xDE, "MFR_SPECIFIC_14", Undefined, Undefined, FT_Undefined },
    { 0xDF, "MFR_SPECIFIC_15", Undefined, Undefined, FT_Undefined },
    { 0xE0, "MFR_SPECIFIC_16", Undefined, Undefined, FT_Undefined },
    { 0xE1, "MFR_SPECIFIC_17", Undefined, Undefined, FT_Undefined },
    { 0xE2, "MFR_SPECIFIC_18", Undefined, Undefined, FT_Undefined },
    { 0xE3, "MFR_SPECIFIC_19", Undefined, Undefined, FT_Undefined },
    { 0xE4, "MFR_SPECIFIC_20", Undefined, Undefined, FT_Undefined },
    { 0xE5, "MFR_SPECIFIC_21", Undefined, Undefined, FT_Undefined },
    { 0xE6, "MFR_SPECIFIC_22", Undefined, Undefined, FT_Undefined },
    { 0xE7, "MFR_SPECIFIC_23", Undefined, Undefined, FT_Undefined },
    { 0xE8, "MFR_SPECIFIC_24", Undefined, Undefined, FT_Undefined },
    { 0xE9, "MFR_SPECIFIC_25", Undefined, Undefined, FT_Undefined },
    { 0xEA, "MFR_SPECIFIC_26", Undefined, Undefined, FT_Undefined },
    { 0xEB, "MFR_SPECIFIC_27", Undefined, Undefined, FT_Undefined },
    { 0xEC, "MFR_SPECIFIC_28", Undefined, Undefined, FT_Undefined },
    { 0xED, "MFR_SPECIFIC_29", Undefined, Undefined, FT_Undefined },
    { 0xEE, "MFR_SPECIFIC_30", Undefined, Undefined, FT_Undefined },
    { 0xEF, "MFR_SPECIFIC_31", Undefined, Undefined, FT_Undefined },
    { 0xF0, "MFR_SPECIFIC_32", Undefined, Undefined, FT_Undefined },
    { 0xF1, "MFR_SPECIFIC_33", Undefined, Undefined, FT_Undefined },
    { 0xF2, "MFR_SPECIFIC_34", Undefined, Undefined, FT_Undefined },
    { 0xF3, "MFR_SPECIFIC_35", Undefined, Undefined, FT_Undefined },
    { 0xF4, "MFR_SPECIFIC_36", Undefined, Undefined, FT_Undefined },
    { 0xF5, "MFR_SPECIFIC_37", Undefined, Undefined, FT_Undefined },
    { 0xF6, "MFR_SPECIFIC_38", Undefined, Undefined, FT_Undefined },
    { 0xF7, "MFR_SPECIFIC_39", Undefined, Undefined, FT_Undefined },
    { 0xF8, "MFR_SPECIFIC_40", Undefined, Undefined, FT_Undefined },
    { 0xF9, "MFR_SPECIFIC_41", Undefined, Undefined, FT_Undefined },
    { 0xFA, "MFR_SPECIFIC_42", Undefined, Undefined, FT_Undefined },
    { 0xFB, "MFR_SPECIFIC_43", Undefined, Undefined, FT_Undefined },
    { 0xFC, "MFR_SPECIFIC_44", Undefined, Undefined, FT_Undefined },
    { 0xFD, "MFR_SPECIFIC_45", Undefined, Undefined, FT_Undefined },
    { 0xFE, "MFR_SPECIFIC_COMMAND_EXT", Undefined, Undefined, FT_Undefined },
    { 0xFF, "PMBUS_COMMAND_EXT", Undefined, Undefined, FT_Undefined },

    { -1, "<error>", Undefined, Undefined, FT_Undefined },
};

const CommandDesc& GetPMBusCommandDesc( U64 id )
{
    if( id < 0 || id > 0xff )
        return pmbus_cmds[ 0x100 ];

    return pmbus_cmds[ id ];
}


// from Smart Battery specs rev 1.1
const CommandDesc smart_batt_cmds[] = {
    { SBC_ManufacturerAccess, "ManufacturerAccess", 2, ReadWrite, FT_Undefined },
    { SBC_RemainingCapacityAlarm, "RemainingCapacityAlarm", 2, ReadWrite, FT_Undefined },
    { SBC_RemainingTimeAlarm, "RemainingTimeAlarm", 2, ReadWrite, FT_Undefined },
    { SBC_BatteryMode, "BatteryMode", 2, ReadWrite, FT_SmartBattBatteryMode },
    { SBC_AtRate, "AtRate", 2, ReadWrite, FT_Undefined },
    { SBC_AtRateTimeToFull, "AtRateTimeToFull", 2, Read, FT_Undefined },
    { SBC_AtRateTimeToEmpty, "AtRateTimeToEmpty", 2, Read, FT_Undefined },
    { SBC_AtRateOK, "AtRateOK", 2, Read, FT_Undefined },
    { SBC_Temperature, "Temperature", 2, Read, FT_Undefined },
    { SBC_Voltage, "Voltage", 2, Read, FT_Undefined },
    { SBC_Current, "Current", 2, Read, FT_Undefined },
    { SBC_AverageCurrent, "AverageCurrent", 2, Read, FT_Undefined },
    { SBC_MaxError, "MaxError", 2, Read, FT_Undefined },
    { SBC_RelativeStateOfCharge, "RelativeStateOfCharge", 2, Read, FT_Undefined },
    { SBC_AbsoluteStateOfCharge, "AbsoluteStateOfCharge", 2, Read, FT_Undefined },
    { SBC_RemainingCapacity, "RemainingCapacity", 2, Read, FT_Undefined },
    { SBC_FullChargeCapacity, "FullChargeCapacity", 2, Read, FT_Undefined },
    { SBC_RunTimeToEmpty, "RunTimeToEmpty", 2, Read, FT_Undefined },
    { SBC_AverageTimeToEmpty, "AverageTimeToEmpty", 2, Read, FT_Undefined },
    { SBC_AverageTimeToFull, "AverageTimeToFull", 2, Read, FT_Undefined },
    { SBC_ChargingCurrent, "ChargingCurrent", Undefined, Read, FT_Undefined },
    { SBC_ChargingVoltage, "ChargingVoltage", Undefined, Read, FT_Undefined },
    { SBC_BatteryStatus, "BatteryStatus", 2, Read, FT_SmartBattBatteryStatus },
    { SBC_CycleCount, "CycleCount", 2, Read, FT_Undefined },
    { SBC_DesignCapacity, "DesignCapacity", 2, Read, FT_Undefined },
    { SBC_DesignVoltage, "DesignVoltage", 2, Read, FT_Undefined },
    { SBC_SpecificationInfo, "SpecificationInfo", 2, Read, FT_SmartBattSpecificationInfo },
    { SBC_ManufactureDate, "ManufactureDate", 2, Read, FT_SmartBattManufactureDate },
    { SBC_SerialNumber, "SerialNumber", 2, Read, FT_Undefined },
    { SBC_ManufacturerName, "ManufacturerName", LengthVariable, Read, FT_Undefined },
    { SBC_DeviceName, "DeviceName", LengthVariable, Read, FT_Undefined },
    { SBC_DeviceChemistry, "DeviceChemistry", LengthVariable, Read, FT_Undefined },
    { SBC_ManufacturerData, "ManufacturerData", LengthVariable, Read, FT_Undefined },
    { SBC_OptionalMfgFunction5, "OptionalMfgFunction5", Undefined, ReadWrite, FT_Undefined },
    { SBC_OptionalMfgFunction4, "OptionalMfgFunction4", Undefined, ReadWrite, FT_Undefined },
    { SBC_OptionalMfgFunction3, "OptionalMfgFunction3", Undefined, ReadWrite, FT_Undefined },
    { SBC_OptionalMfgFunction2, "OptionalMfgFunction2", Undefined, ReadWrite, FT_Undefined },
    { SBC_OptionalMfgFunction1, "OptionalMfgFunction1", Undefined, ReadWrite, FT_Undefined },

    { -1, "<error>", Undefined, Undefined, FT_Undefined },
};

const CommandDesc& GetSmartBatteryCommandDesc( U64 id )
{
    int c = 0;
    for( c = 0; smart_batt_cmds[ c ].id != -1; ++c )
    {
        if( smart_batt_cmds[ c ].id == id )
            return smart_batt_cmds[ c ];
    }

    return smart_batt_cmds[ ( sizeof( smart_batt_cmds ) / sizeof( CommandDesc ) ) - 1 ];
}
