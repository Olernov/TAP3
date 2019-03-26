#define TL_OK					0		// �������� ������ �������
#define TL_PARAM_ERROR			-1		// ������ �������� ���������� (����� ����� � ID)
#define TL_FILEERROR			-2		// ������ ������ ��������� �����
#define TL_DECODEERROR			-3		// ������ ������������� ASN
#define TL_NOTIFICATION			-4		// ����-�����������
#define TL_CONNECTERROR			-5		// ������ �������� � ����
#define TL_MISSINGSTRUCT		-6		// ����������� ������������ ��������� (mandatory)
#define TL_ORACLEERROR			-7		// ������ ������ � �����, ��. err-����
#define TL_NEWCOMPONENT			-8		// ���� �������� ����������, �� �������������� ��������
#define TL_AUDITFAULT			-9		// ����������� �������� ���������� ���� ���-�� ������� � ���������� � Audit Control Info
#define TL_WRONGCODE			-10		// ������ �� �������������� UTC offset, Exchange Rate ��� Recording Entity
#define TL_TAP_NOT_VALIDATED	-11		// ���������� �������� ��������� �����
#define TL_UNKNOWN				-999		// ����������� ������ (����������)

// ���� ��������� ����
#define LOG_INFO			0
#define LOG_WARNING			1
#define LOG_ERROR			3

// file statuses in DB
#define INFILE_STATUS_NEW					0
#define INFILE_LOADED_FOR_CHARGING			5
#define INFILE_STATUS_FATAL					-80
#define INFILE_STATUS_UNABLE_TO_VALIDATE	-10
#define INFILE_STATUS_UNKNOWN_ERROR			-999
#define OUTFILE_IN_PROGRESS					10
#define OUTFILE_READY_FOR_SENDING			20
#define OUTFILE_CREATED_AND_SENT			30

#define INRAP_READY_TO_SEND_ACK				3
#define INRAP_ACK_SENT						7
#define OUTRAP_ACKNOWLEDGE_RECEIVED			45




