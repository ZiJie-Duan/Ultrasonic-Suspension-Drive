#include "stm32f10x.h"                  // Device header


void Init_Voice(void){
	
		const uint16_t WaveData[] = {
	0x52, 0x49, 0x46, 0x46, 0x04, 0x00, 0x57, 0x41, 0x56, 0x45, 0x66, 0x74, 0x20, 0x10, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x10, 0x00, 0x64, 
	0x61, 0x74, 0x61, 0x12, 0x04, 0x00, 0x84, 0x75, 0x00, 0x64, 0x40, 0x05, 0x26, 0x11, 0x16, 0x01, 
	0x44, 0x04, 0x04, 0x04, 0x23, 0x05, 0x52, 0x77, 0x07, 0x05, 0x00, 0x98, 0x45, 0x84, 0x03, 0x08, 
	0x01, 0x02, 0x13, 0x05, 0x32, 0x06, 0x20, 0x98, 0x09, 0x07, 0x42, 0x11, 0x00, 0x99, 0x05, 0x08, 
	0x01, 0x08, 0x03, 0x94, 0x05, 0x01, 0x08, 0x74, 0x76, 0x25, 0x65, 0x70, 0x01, 0x05, 0x44, 0x31, 
	0x00, 0x81, 0x33, 0x01, 0x71, 0x14, 0x04, 0x17, 0x13, 0x04, 0x06, 0x05, 0x01, 0x59, 0x80, 0x93, 
	0x49, 0x28, 0x05, 0x02, 0x11, 0x30, 0x29, 0x06, 0x92, 0x01, 0x01, 0x00, 0x05, 0x60, 0x12, 0x26, 
	0x10, 0x20, 0x01, 0x08, 0x95, 0x00, 0x89, 0x00, 0x74, 0x04, 0x76, 0x09, 0x05, 0x10, 0x60, 0x00, 
	0x72, 0x01, 0x18, 0x07, 0x01, 0x82, 0x86, 0x65, 0x97, 0x95, 0x02, 0x95, 0x06, 0x77, 0x08, 0x07, 
	0x06, 0x08, 0x96, 0x51, 0x08, 0x09, 0x86, 0x61, 0x01, 0x22, 0x09, 0x76, 0x73, 0x39, 0x04, 0x68, 
	0x90, 0x05, 0x20, 0x03, 0x71, 0x14, 0x08, 0x01, 0x75, 0x10, 0x00, 0x10, 0x94, 0x40, 0x14, 0x16, 
	0x33, 0x05, 0x12, 0x16, 0x33, 0x03, 0x47, 0x15, 0x17, 0x12, 0x69, 0x06, 0x67, 0x09, 0x11, 0x60, 
	0x94, 0x70, 0x09, 0x26, 0x53, 0x15, 0x73, 0x12, 0x81, 0x00, 0x09, 0x04, 0x02, 0x09, 0x56, 0x07, 
	0x17, 0x16, 0x15, 0x12, 0x92, 0x10, 0x15, 0x16, 0x18, 0x17, 0x62, 0x14, 0x18, 0x17, 0x91, 0x12, 
	0x18, 0x81, 0x07, 0x80, 0x02, 0x07, 0x03, 0x11, 0x07, 0x94, 0x76, 0x01, 0x10, 0x10, 0x43, 0x12, 
	0x07, 0x07, 0x06, 0x71, 0x15, 0x02, 0x22, 0x03, 0x02, 0x66, 0x03, 0x07, 0x56, 0x28, 0x37, 0x33, 
	0x68, 0x09, 0x89, 0x17, 0x67, 0x68, 0x29, 0x28, 0x71, 0x14, 0x21, 0x17, 0x01, 0x18, 0x12, 0x99, 
	0x20, 0x18, 0x15, 0x59, 0x11, 0x10, 0x18, 0x60, 0x14, 0x13, 0x23, 0x17, 0x54, 0x18, 0x15, 0x23, 
	0x43, 0x33, 0x79, 0x22, 0x16, 0x08, 0x88, 0x10, 0x00, 0x09, 0x16, 0x17, 0x12, 0x14, 0x78, 0x03, 
	0x05, 0x35, 0x12, 0x92, 0x20, 0x38, 0x00, 0x35, 0x57, 0x01, 0x01, 0x20, 0x09, 0x36, 0x92, 0x08, 
	0x95, 0x18, 0x85, 0x54, 0x12, 0x17, 0x34, 0x55, 0x01, 0x35, 0x02, 0x49, 0x15, 0x73, 0x45, 0x14, 
	0x61, 0x68, 0x18, 0x14, 0x28, 0x30, 0x15, 0x15, 0x77, 0x13, 0x05, 0x01, 0x02, 0x14, 0x09, 0x38, 
	0x00, 0x47, 0x82, 0x08, 0x02, 0x02, 0x04, 0x02, 0x07, 0x04, 0x79, 0x32, 0x17, 0x22, 0x68, 0x60, 
	0x23, 0x74, 0x18, 0x05, 0x08, 0x03, 0x10, 0x02, 0x84, 0x08, 0x08, 0x64, 0x12, 0x18, 0x13, 0x14, 
	0x71, 0x19, 0x19, 0x50, 0x72, 0x74, 0x34, 0x07, 0x08, 0x35, 0x07, 0x25, 0x05, 0x27, 0x01, 0x57, 
	0x34, 0x08, 0x07, 0x97, 0x73, 0x20, 0x03, 0x95, 0x31, 0x42, 0x39, 0x00, 0x06, 0x15, 0x68, 0x24, 
	0x09, 0x85, 0x06, 0x55, 0x03, 0x49, 0x11, 0x39, 0x53, 0x19, 0x42, 0x00, 0x75, 0x09, 0x12, 0x12, 
	0x11, 0x77, 0x15, 0x23, 0x34, 0x28, 0x47, 0x31, 0x30, 0x21, 0x38, 0x68, 0x19, 0x31, 0x66, 0x27, 
	0x27, 0x25, 0x50, 0x65, 0x19, 0x08, 0x51, 0x72, 0x47, 0x74, 0x89, 0x14, 0x96, 0x44, 0x66, 0x34, 
	0x12, 0x38, 0x23, 0x23, 0x65, 0x13, 0x68, 0x50, 0x07, 0x33, 0x15, 0x55, 0x95, 0x11, 0x03, 0x03, 
	0x00, 0x11, 0x25, 0x13, 0x44, 0x14, 0x29, 0x17, 0x09, 0x09, 0x03, 0x00, 0x07, 0x10, 0x07, 0x40, 
	0x21, 0x93, 0x23, 0x14, 0x28, 0x81, 0x23, 0x07, 0x19, 0x49, 0x54, 0x04, 0x11, 0x87, 0x20, 0x55, 
	0x28, 0x62, 0x21, 0x59, 0x21, 0x01, 0x74, 0x05, 0x04, 0x14, 0x09, 0x00, 0x94, 0x07, 0x93, 0x33, 
	0x63, 0x98, 0x80, 0x36, 0x50, 0x40, 0x00, 0x07, 0x08, 0x09, 0x04, 0x05, 0x83, 0x02, 0x19, 0x35, 
	0x25, 0x21, 0x34, 0x10, 0x58, 0x28, 0x28, 0x23, 0x06, 0x64, 0x05, 0x15, 0x25, 0x27, 0x52, 0x25, 
	0x20, 0x67, 0x68, 0x69, 0x11, 0x28, 0x04, 0x15, 0x95, 0x43, 0x66, 0x84, 0x07, 0x49, 0x40, 0x03, 
	0x68, 0x55, 0x93, 0x64, 0x09, 0x02, 0x45, 0x09, 0x43, 0x14, 0x15, 0x18, 0x09, 0x59, 0x18, 0x04, 
	0x08, 0x88, 0x53, 0x37, 0x96, 0x39, 0x20, 0x84, 0x21, 0x03, 0x23, 0x05, 0x22, 0x28, 0x49, 0x22, 
	0x31, 0x29, 0x27, 0x83, 0x16, 0x15, 0x44, 0x98, 0x28, 0x19, 0x14, 0x88, 0x60, 0x07, 0x83, 0x09, 
	0x87, 0x02, 0x16, 0x09, 0x15, 0x06, 0x56, 0x12, 0x06, 0x04, 0x35, 0x37, 0x83, 0x95, 0x52, 0x37, 
	0x06, 0x75, 0x01, 0x05, 0x14, 0x73, 0x01, 0x01, 0x83, 0x10, 0x55, 0x13, 0x12, 0x66, 0x10, 0x09, 
	0x25, 0x25, 0x42, 0x16, 0x27, 0x20, 0x03, 0x01, 0x62, 0x59, 0x16, 0x19, 0x00, 0x69, 0x91, 0x59, 
	0x75, 0x25, 0x02, 0x08, 0x01, 0x41, 0x00, 0x00, 0x10, 0x36, 0x08, 0x24, 0x09, 0x78, 0x05, 0x19, 
	0x02, 0x22, 0x91, 0x33, 0x04, 0x05, 0x52, 0x03, 0x17, 0x26, 0x20, 0x86, 0x23, 0x01, 0x15, 0x07, 
	0x07, 0x10, 0x10, 0x42, 0x15, 0x20, 0x27, 0x20, 0x22, 0x18, 0x67, 0x09, 0x73, 0x53, 0x29, 0x16, 
	0x33, 0x47, 0x23, 0x74, 0x20, 0x10, 0x70, 0x01, 0x08, 0x16, 0x68, 0x16, 0x71, 0x07, 0x06, 0x10, 
	0x13, 0x31, 0x06, 0x10, 0x23, 0x11, 0x44, 0x39, 0x66, 0x77, 0x65, 0x09, 0x69, 0x08, 0x88, 0x10, 
	0x31, 0x24, 0x26, 0x03, 0x35, 0x36, 0x38, 0x31, 0x00, 0x51, 0x16, 0x65, 0x11, 0x47, 0x14, 0x41, 
	0x12, 0x07, 0x02, 0x04, 0x23, 0x84, 0x68, 0x80, 0x02, 0x95, 0x72, 0x19, 0x55, 0x98, 0x11, 0x40, 
	0x77, 0x09, 0x01, 0x00, 0x13, 0x02, 0x02, 0x82, 0x04, 0x04, 0x08, 0x46, 0x09, 0x59, 0x18, 0x21, 
	0x76, 0x18, 0x29, 0x11, 0x37, 0x11, 0x97, 0x16, 0x23, 0x51, 0x34, 0x41, 0x14, 0x21, 0x18, 0x17, 
	0x19, 0x32, 0x17, 0x29, 0x21, 0x18, 0x94, 0x18, 0x65, 0x04, 0x25, 0x29, 0x19, 0x12, 0x60, 0x71, 
	0x17, 0x05, 0x63, 0x96, 0x56, 0x99, 0x78, 0x52, 0x57, 0x40, 0x14, 0x68, 0x30, 0x19, 0x07, 0x43, 
	0x01, 0x10, 0x15, 0x19, 0x11, 0x81, 0x14, 0x16, 0x05, 0x64, 0x14, 0x20, 0x89, 0x33, 0x33, 0x24, 
	0x33, 0x43, 0x30, 0x08, 0x95, 0x40, 0x05, 0x83, 0x81, 0x76, 0x28, 0x35, 0x41, 0x99, 0x73, 0x07, 
	0x31, 0x05, 0x85, 0x55, 0x73, 0x45, 0x20, 0x94, 0x45, 0x06, 0x40, 0x00, 0x05, 0x04, 0x17, 0x06, 
	0x30, 0x13, 0x18, 0x12, 0x18, 0x86, 0x22, 0x05, 0x15, 0x08, 0x19, 0x06, 0x18, 0x26, 0x28, 0x37, 
	0x16, 0x03, 0x18, 0x14, 0x43, 0x03, 0x79, 0x03, 0x95, 0x01, 0x75, 0x12, 0x73, 0x06, 0x68, 0x05, 
	0x19, 0x06, 0x04, 0x45, 0x01, 0x09, 0x19, 0x15, 0x19, 0x06, 0x29, 0x28, 0x62, 0x25, 0x46, 0x11, 
	0x38, 0x89, 0x01, 0x02, 0x50, 0x55, 0x00, 0x23, 0x42, 0x31, 0x04, 0x62, 0x31, 0x03, 0x19, 0x51, 
	0x11, 0x05, 0x07, 0x08, 0x23, 0x21, 0x23, 0x49, 0x12, 0x04, 0x05, 0x05, 0x01, 0x02, 0x78, 0x94, 
	0x22, 0x13, 0x67, 0x26, 0x89, 0x32, 0x40, 0x06, 0x47, 0x00, 0x09, 0x74, 0x00, 0x13, 0x19, 0x03, 
	0x94, 0x82, 0x05, 0x08, 0x16, 0x03, 0x06, 0x12, 0x29, 0x04, 0x01, 0x04, 0x42, 0x13, 0x31, 0x12, 
	0x88, 0x06, 0x22, 0x37, 0x03, 0x42, 0x50, 0x08, 0x04, 0x71, 0x29, 0x16, 0x57, 0x23, 0x26, 0x54, 
	0x05, 0x08, 0x37, 0x08, 0x66, 0x61, 0x12, 0x27, 0x07, 0x58, 0x07, 0x04, 0x38, 0x07, 0x01, 0x30, 
	0x22, 0x01, 0x63, 0x09, 0x83, 0x65, 0x59, 0x93, 0x68, 0x14, 0x01, 0x11, 0x82, 0x15, 0x58, 0x34, 
	0x26, 0x25, 0x10, 0x28, 0x86, 0x16, 0x17, 0x22, 0x20, 0x61, 0x97, 0x27, 0x45, 0x30, 0x22, 0x15, 
	0x32, 0x05, 0x87, 0x51, 0x84, 0x55, 0x20, 0x10, 0x07, 0x34, 0x53, 0x61, 0x80, 0x22, 0x47, 0x25, 
	0x24, 0x94, 0x06, 0x05, 0x38, 0x63, 0x01, 0x61, 0x08, 0x14, 0x07, 0x68, 0x12, 0x14, 0x40, 0x51, 
	0x19, 0x24, 0x36, 0x14, 0x29, 0x19, 0x34, 0x27, 0x22, 0x95, 0x21, 0x20, 0x11, 0x04, 0x14, 0x51, 
	0x04, 0x47, 0x24, 0x07, 0x06, 0x96, 0x01, 0x90, 0x96, 0x08, 0x07, 0x01, 0x52, 0x96, 0x79, 0x26, 
	0x97, 0x35, 0x81, 0x34, 0x85, 0x10, 0x13, 0x78, 0x09, 0x54, 0x24, 0x92, 0x24, 0x09, 0x23, 0x69, 
	0x16, 0x09, 0x12, 0x73, 0x08, 0x81, 0x11, 0x16, 0x25, 0x03, 0x69, 0x09, 0x83, 0x27, 0x26, 0x02, 
	0x21, 0x86, 0x22, 0x91, 0x08, 0x03, 0x04, 0x45, 0x15, 0x95, 0x71, 0x30, 0x15, 0x06, 0x99, 0x64, 
	0x42, 0x00, 0x04, 0x14, 0x27, 0x12, 0x80, 0x15, 0x19, 0x58, 0x18, 0x10, 0x09, 0x06, 0x22, 0x13, 
	0x06, 0x12, 0x18, 0x61, 0x20, 0x29, 0x17, 0x19, 0x48, 0x26, 0x53, 0x19, 0x10, 0x37, 0x13, 0x11, 
	0x79, 0x07, 0x62, 0x36, 0x12, 0x27, 0x19, 0x05, 0x92, 0x16, 0x23, 0x52, 0x16, 0x88, 0x09, 0x61, 
	0x99, 0x59, 0x76, 0x27, 0x02, 0x36, 0x23, 0x00, 0x07, 0x31, 0x14, 0x51, 0x49, 0x76, 0x87, 0x29, 
	0x01, 0x43, 0x27, 0x08, 0x24, 0x07, 0x33, 0x29, 0x61, 0x17, 0x84, 0x27, 0x27, 0x45, 0x17, 0x62, 
	0x18, 0x21, 0x19, 0x51, 0x33, 0x69, 0x55, 0x22, 0x27, 0x49, 0x14, 0x06, 0x87, 0x70, 0x65, 0x16, 
	0x55, 0x66, 0x22, 0x97, 0x21, 0x86, 0x36, 0x86, 0x06, 0x09, 0x09, 0x97, 0x02, 0x44, 0x00, 0x16, 
	0x08, 0x15, 0x05, 0x10, 0x24, 0x05, 0x06, 0x28, 0x17, 0x63, 0x16, 0x57, 0x17, 0x41, 0x23, 0x09, 
	0x35, 0x62, 0x18, 0x07, 0x14, 0x10, 0x12, 0x18, 0x99, 0x62, 0x23, 0x21, 0x76, 0x21, 0x25, 0x16, 
	0x05, 0x46, 0x04, 0x03, 0x10, 0x11, 0x44, 0x09, 0x89, 0x08, 0x19, 0x40, 0x05, 0x01, 0x24, 0x66, 
	0x45, 0x24, 0x44, 0x52, 0x16, 0x24, 0x22, 0x93, 0x56, 0x45, 0x04, 0x11, 0x19, 0x13, 0x84, 0x14, 
	0x60, 0x18, 0x96, 0x30, 0x63, 0x29, 0x21, 0x19, 0x15, 0x07, 0x03, 0x09, 0x20, 0x09, 0x08, 0x04, 
	0x67, 0x06, 0x39, 0x01, 0x00, 0x64, 0x76, 0x06, 0x81, 0x04, 0x41, 0x11, 0x94, 0x03, 0x02, 0x64, 
	0x74, 0x45, 0x10, 0x33, 0x25, 0x06, 0x20, 0x73, 0x23, 0x17, 0x00, 0x80, 0x79, 0x04, 0x01, 0x01, 
	0x07, 0x39, 0x05, 0x38, 0x01, 0x27, 0x21, 0x33, 0x21, 0x36, 0x22, 0x17, 0x09, 0x00, 0x05, 0x00, 
	0x13, 0x10, 0x15, 0x86, 0x16, 0x78, 0x55, 0x14, 0x15, 0x34, 0x01, 0x07, 0x60, 0x01, 0x02, 0x19, 
	0x14, 0x96, 0x20, 0x67, 0x26, 0x73, 0x00, 0x43, 0x25, 0x32, 0x21, 0x54, 0x11, 0x34, 0x41, 0x06, 
	0x84, 0x00, 0x01, 0x07, 0x99, 0x07, 0x00, 0x94, 0x66, 0x73, 0x18, 0x10, 0x31, 0x97, 0x44, 0x42, 
	0x44, 0x77, 0x43, 0x11, 0x10, 0x05, 0x13, 0x97, 0x17, 0x99, 0x14, 0x14, 0x05, 0x06, 0x67, 0x93, 
	0x57, 0x39, 0x02, 0x88, 0x55, 0x03, 0x76, 0x32, 0x45, 0x23, 0x60, 0x07, 0x09, 0x01, 0x28, 0x54, 
	0x30, 0x85, 0x27, 0x73, 0x12, 0x93, 0x00, 0x42, 0x04, 0x72, 0x08, 0x67, 0x71, 0x17, 0x13, 0x27, 
	0x12, 0x25, 0x28, 0x41, 0x39, 0x28, 0x08, 0x02, 0x13, 0x64, 0x10, 0x65, 0x22, 0x38, 0x52, 0x39, 
	0x63, 0x13, 0x89, 0x04, 0x84, 0x21, 0x96, 0x20, 0x18, 0x08, 0x03, 0x42, 0x88, 0x38, 0x07, 0x26, 
	0x99, 0x72, 0x09, 0x07, 0x00, 0x04, 0x04, 0x85, 0x15, 0x39, 0x03, 0x56, 0x12, 0x74, 0x97, 0x71, 
	0x23, 0x72, 0x25, 0x32, 0x96, 0x31, 0x01, 0x66, 0x13, 0x94, 0x02, 0x15, 0x78, 0x14, 0x54, 0x00, 
	0x07, 0x29, 0x32, 0x20, 0x09, 0x01, 0x01, 0x11, 0x59, 0x02, 0x27, 0x09, 0x34, 0x19, 0x12, 0x15, 
	0x84, 0x96, 0x54, 0x51, 0x40, 0x66, 0x27, 0x39, 0x02, 0x25, 0x30, 0x20, 0x00, 0x38, 0x56, 0x24, 
	0x03, 0x06, 0x91, 0x01, 0x32, 0x40, 0x97, 0x00, 0x57, 0x12, 0x21, 0x58, 0x18, 0x01, 0x05, 0x13, 
	0x04, 0x13, 0x73, 0x18, 0x23, 0x70, 0x11, 0x75, 0x13, 0x16, 0x57, 0x23, 0x52, 0x25, 0x24, 0x47, 
	0x29, 0x40, 0x29, 0x27, 0x51, 0x02, 0x09, 0x32, 0x78, 0x47, 0x93, 0x91, 0x31, 0x30, 0x64, 0x08, 
	0x06, 0x22, 0x41, 0x96, 0x59, 0x50, 0x68, 0x78, 0x94, 0x24, 0x24, 0x97, 0x16, 0x68, 0x28, 0x10, 
	0x13, 0x07, 0x16, 0x14, 0x13, 0x74, 0x20, 0x16, 0x26, 0x20, 0x86, 0x20, 0x76, 0x16, 0x59, 0x58, 
	0x19, 0x49, 0x63, 0x94, 0x24, 0x40, 0x01, 0x91, 0x98, 0x17, 0x73, 0x00, 0x79, 0x34, 0x79, 0x85, 
	0x42, 0x40, 0x19, 0x85, 0x21, 0x03, 0x46, 0x15, 0x75, 0x12, 0x09, 0x18, 0x23, 0x84, 0x18, 0x15, 
	0x95, 0x14, 0x09, 0x65, 0x04, 0x73, 0x06, 0x40, 0x04, 0x78, 0x03, 0x19, 0x40, 0x27, 0x53, 0x32, 
	0x03, 0x05, 0x57, 0x42, 0x81, 0x50, 0x73, 0x04, 0x33, 0x87, 0x88, 0x00, 0x02, 0x01, 0x33, 0x25, 
	0x91, 0x01, 0x24, 0x52, 0x36, 0x13, 0x20, 0x08, 0x01, 0x14, 0x52, 0x18, 0x18, 0x63, 0x10, 0x58, 
	0x02, 0x74, 0x16, 0x64, 0x14, 0x48, 0x19, 0x70, 0x19, 0x15, 0x14, 0x62, 0x15, 0x69, 0x29, 0x43, 
	0x27, 0x30, 0x74, 0x30, 0x30, 0x04, 0x05, 0x03, 0x42, 0x04, 0x84, 0x12, 0x09, 0x13, 0x89, 0x05, 
	0x05, 0x15, 0x01, 0x20, 0x77, 0x00, 0x91, 0x21, 0x83, 0x45, 0x83, 0x02, 0x02, 0x61, 0x31, 0x78, 
	0x24, 0x87, 0x19, 0x23, 0x12, 0x91, 0x09, 0x17, 0x85, 0x07, 0x48, 0x10, 0x02, 0x14, 0x20, 0x30, 
	0x19, 0x27, 0x32, 0x31, 0x23, 0x99, 0x26, 0x20, 0x67, 0x05, 0x14, 0x14, 0x79, 0x03, 0x48, 0x01, 
	0x42, 0x11, 0x83, 0x22, 0x50, 0x18, 0x75, 0x92, 0x19, 0x98, 0x97, 0x99, 0x95, 0x85, 0x28, 0x07, 
	0x04, 0x14, 0x15, 0x23, 0x16, 0x23, 0x21, 0x54, 0x19, 0x14, 0x08, 0x04, 0x76, 0x99, 0x70, 0x21, 
	0x23, 0x17, 0x32, 0x45, 0x11, 0x28, 0x03, 0x24, 0x50, 0x17, 0x01, 0x41, 0x21, 0x52, 0x49, 0x59, 
	0x26, 0x69, 0x13, 0x04, 0x76, 0x08, 0x12, 0x02, 0x04, 0x96, 0x04, 0x02, 0x04, 0x00, 0x16, 0x25, 
	0x67, 0x65, 0x36, 0x05, 0x19, 0x24, 0x22, 0x43, 0x65, 0x11, 0x90, 0x05, 0x02, 0x07, 0x37, 0x04, 
	0x96, 0x01, 0x19, 0x56, 0x00, 0x00, 0x07, 0x15, 0x28, 0x36, 0x42, 0x40, 0x11, 0x82, 0x45, 0x33, 
	0x97, 0x70, 0x07, 0x64, 0x01, 0x01, 0x60, 0x55, 0x21, 0x99, 0x54, 0x09, 0x46, 0x83, 0x94, 0x53, 
	0x36, 0x00, 0x94, 0x04, 0x10, 0x27, 0x23, 0x25, 0x79, 0x29, 0x24, 0x10, 0x24, 0x40, 0x10, 0x13, 
	0x48, 0x04, 0x77, 0x05, 0x07, 0x04, 0x85, 0x05, 0x07, 0x30, 0x14, 0x10, 0x09, 0x13, 0x17, 0x12, 
	0x73, 0x08, 0x26, 0x27, 0x23, 0x18, 0x08, 0x69, 0x15, 0x19, 0x60, 0x98, 0x50, 0x97, 0x68, 0x78, 
	0x17, 0x14, 0x19, 0x42, 0x21, 0x09, 0x06, 0x47, 0x13, 0x83, 0x26, 0x42, 0x46, 0x98, 0x75, 0x88, 
	0x21, 0x27, 0x23, 0x28, 0x73, 0x15, 0x05, 0x89, 0x02, 0x88, 0x50, 0x06, 0x74, 0x14, 0x19, 0x59, 
	0x80, 0x06, 0x42, 0x45, 0x72, 0x33, 0x86, 0x32, 0x95, 0x23, 0x15, 0x09, 0x43, 0x09, 0x04, 0x93, 
	0x16, 0x46, 0x14, 0x12, 0x20, 0x18, 0x10, 0x67, 0x21, 0x03, 0x78, 0x70, 0x55, 0x32, 0x83, 0x10, 
	0x57, 0x22, 0x16, 0x63, 0x14, 0x56, 0x15, 0x21, 0x25, 0x07, 0x08, 0x39, 0x26, 0x04, 0x08, 0x10, 
	0x31, 0x37, 0x23, 0x33, 0x92, 0x42, 0x76, 0x36, 0x30, 0x11, 0x81, 0x69, 0x56, 0x24, 0x48, 0x47, 
	0x15, 0x45, 0x31, 0x11, 0x76, 0x16, 0x53, 0x73, 0x03, 0x96, 0x07, 0x37, 0x17, 0x89, 0x41, 0x37, 
	0x59, 0x00, 0x81, 0x06, 0x60, 0x27, 0x25, 0x31, 0x66, 0x29, 0x28, 0x21, 0x96, 0x13, 0x56, 0x63, 
	0x12, 0x62, 0x17, 0x06, 0x13, 0x58, 0x10, 0x46, 0x26, 0x78, 0x36, 0x24, 0x38, 0x83, 0x49, 0x50, 
	0x45, 0x94, 0x26, 0x51, 0x20, 0x23, 0x13, 0x01, 0x07, 0x10, 0x11, 0x83, 0x74, 0x72, 0x02, 0x07, 
	0x34, 0x07, 0x28, 0x00, 0x16, 0x87, 0x33, 0x54, 0x88, 0x88, 0x08, 0x10, 0x13, 0x98, 0x29, 0x28, 
	0x17, 0x43, 0x19, 0x19, 0x32, 0x15, 0x12, 0x18, 0x62, 0x24, 0x23, 0x10, 0x30, 0x08, 0x30, 0x04, 
	0x06, 0x47, 0x70, 0x98, 0x86, 0x23, 0x13, 0x33, 0x36, 0x24, 0x17, 0x53, 0x03, 0x50, 0x37, 0x37, 
	0x06, 0x84, 0x73, 0x21, 0x03, 0x40, 0x07, 0x44, 0x07, 0x14, 0x13, 0x37, 0x15, 0x06, 0x60, 0x11, 
	0x03, 0x39, 0x49, 0x52, 0x87, 0x70, 0x05, 0x95, 0x09, 0x19, 0x65, 0x95, 0x77, 0x34, 0x29, 0x26, 
	0x16, 0x19, 0x77, 0x13, 0x51, 0x13, 0x96, 0x00, 0x66, 0x04, 0x49, 0x03, 0x13, 0x17, 0x84, 0x02, 
	0x36, 0x42, 0x37, 0x85, 0x35, 0x31, 0x26, 0x30, 0x19, 0x02, 0x98, 0x16, 0x97, 0x01, 0x03, 0x08, 
	0x24, 0x12, 0x99, 0x01, 0x06, 0x05, 0x90, 0x01, 0x21, 0x60, 0x53, 0x19, 0x19, 0x13, 0x05, 0x89, 
	0x24, 0x33, 0x32, 0x32, 0x54, 0x21, 0x02, 0x20, 0x06, 0x05, 0x36, 0x08, 0x45, 0x00, 0x97, 0x43, 
	0x18, 0x09, 0x06, 0x11, 0x13, 0x11, 0x65, 0x09, 0x68, 0x36, 0x75, 0x15, 0x18, 0x06, 0x01, 0x10, 
	0x15, 0x88, 0x04, 0x68, 0x06, 0x01, 0x37, 0x11, 0x39, 0x16, 0x18, 0x11, 0x00, 0x02, 0x94, 0x05, 
	0x00, 0x75, 0x71, 0x74, 0x15, 0x00, 0x03, 0x64, 0x42, 0x23, 0x32, 0x92, 0x26, 0x25, 0x34, 0x20, 
	0x23, 0x16, 0x11, 0x06, 0x11, 0x58, 0x04, 0x13, 0x45, 0x12, 0x02, 0x04, 0x75, 0x03, 0x06, 0x18, 
	0x09, 0x12, 0x81, 0x18, 0x16, 0x09, 0x01, 0x28, 0x69, 0x92, 0x69, 0x89, 0x54, 0x81, 0x05, 0x08, 
	0x81, 0x52, 0x07, 0x55, 0x02, 0x46, 0x27, 0x06, 0x68, 0x08, 0x09, 0x08, 0x04, 0x68, 0x09, 0x05, 
	0x06, 0x07, 0x06, 0x22, 0x74, 0x76, 0x18, 0x14, 0x17, 0x16, 0x82, 0x14, 0x53, 0x80, 0x23, 0x40, 
	0x15, 0x09, 0x72, 0x09, 0x03, 0x72, 0x04, 0x00, 0x04, 0x74, 0x03, 0x58, 0x01, 0x03, 0x00, 0x04, 
	0x15, 0x08, 0x86, 0x03, 0x03, 0x95, 0x97, 0x86, 0x23, 0x58, 0x15, 0x18, 0x13, 0x12, 0x11, 0x08, 
	0x16, 0x16, 0x34, 0x07, 0x13, 0x25, 0x84, 0x00, 0x57, 0x03, 0x04, 0x01, 0x02, 0x99, 0x07, 0x14, 
	0x92, 0x17, 0x34, 0x16, 0x33, 0x14, 0x99, 0x08, 0x43, 0x16, 0x79, 0x06, 0x17, 0x24, 0x82, 0x32, 
	0x28, 0x08, 0x79, 0x07, 0x63, 0x17, 0x06, 0x14, 0x10, 0x47, 0x12, 0x12, 0x20, 0x08, 0x84, 0x45, 
	0x78, 0x26, 0x00, 0x46, 0x00, 0x06, 0x02, 0x52, 0x05, 0x15, 0x18, 0x21, 0x28, 0x59, 0x22, 0x16, 
	0x34, 0x18, 0x18, 0x05, 0x89, 0x80, 0x39, 0x01, 0x44, 0x00, 0x06, 0x66, 0x00, 0x06, 0x10, 0x24, 
	};
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE ); //使能 PORTA 时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //无意义
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE ); //使能 DAC 通道时钟

	DAC_InitTypeDef DAC_InitType;
	DAC_InitType.DAC_Trigger=DAC_Trigger_T2_TRGO; //使用TIM2作为触发源
	DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_None;//不使用波形发生
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;
	DAC_InitType.DAC_OutputBuffer=DAC_OutputBuffer_Disable ; //DAC1 输出缓存关闭
	DAC_Init(DAC_Channel_1,&DAC_InitType); //初始化 DAC 通道 1 
	DAC_Cmd(DAC_Channel_1, ENABLE); //使能 DAC1
	
	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	/* TIM2基本定时器配置 */
	// TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
	TIM_TimeBaseStructure.TIM_Period = (20-1);//定时周期 20  
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;//预分频，不分频 72M / (0+1) = 72M
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;//时钟分频系数
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	/* 配置TIM2触发源 */
	TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);
	/* 使能TIM2 */
	TIM_Cmd(TIM2, ENABLE);
	
	
	while(1){
		for( int a = 0; a < 2560; a = a + 1 )
   {
      DAC_SetChannel1Data(DAC_Align_12b_R, WaveData[a]);
	 }
	}
	

}



