#ifndef EMVTags_h
#define EMVTags_h

/**
 * Issuer Identification Number (IIN) <p> The number that identifies the major industry and the
 * card issuer and that forms the first part of the Primary Account Number (PAN)
 */
#define TAG_42_ISSUER_IDENTIFICATION_NUMBER 0x42

/**
 * Application Identifier (ADF Name) <p> The ADF Name identifies the application as described
 * in [ISO 7816-5]. The AID is made up of the Registered Application Provider Identifier (RID)
 * and the Proprietary Identifier Extension (PIX).
 */
#define TAG_4F_APPLICATION_IDENTIFIER 0x4F

/**
 * Application Label <p> Mnemonic associated with the AID according to ISO/IEC 7816-5
 */
#define TAG_50_APPLICATION_LABEL 0x50

/**
 * Command to perform <p> В
 */
#define TAG_52_COMMAND_TO_PERFORM 0x52

/**
 * Track 1 Data <p> Track 1 Data contains the data objects of the track 1 according to [ISO/IEC
 * 7813] Structure B, excluding start sentinel, end sentinel and LRC. The Track 1 Data may be
 * present in the file read using the READ RECORD command during a mag-stripe mode transaction.
 */
#define TAG_56_TRACK_1_DATA 0x56

/**
 * Track 2 Equivalent Data <p> Contains the data objects of the track 2, in accordance with
 * [ISO/IEC 7813], excluding start sentinel, end sentinel, and LRC.
 */
#define TAG_57_TRACK_2_EQUIVALENT_DATA 0x57

/**
 * Application Primary Account Number (PAN) <p> Valid cardholder account number
 */
#define TAG_5A_APPLICATION_PRIMARY_ACCOUNT_NUMBER 0x5A

/**
 * Deleted (see 9D) <p> В
 */
#define TAG_5D_DELETED 0x5D

/**
 * Cardholder Name <p> Indicates cardholder name according to ISO 7813
 */
#define TAG_5F20_CARDHOLDER_NAME 0x5F20

/**
 * Application Expiration Date <p> Date after which application expires. The date is expressed
 * in the YYMMDD format. For MasterCard applications, if the value of YY ranges from '00' to
 * '49' the date reads 20YYMMDD. If the value of YY ranges from '50' to '99' the date reads
 * 19YYMMDD.
 */
#define TAG_5F24_APPLICATION_EXPIRATION_DATE 0x5F24

/**
 * Application Effective Date <p> Date from which the application may be used. The date is
 * expressed in the YYMMDD format. For MasterCard branded applications if the value of YY ranges
 * from '00' to '49' the date reads 20YYMMDD. If the value of YY ranges from '50' to '99', the
 * date reads 19YYMMDD.
 */
#define TAG_5F25_APPLICATION_EFFECTIVE_DATE 0x5F25

/**
 * Issuer Country Code <p> Indicates the country of the issuer according to ISO 3166-1
 */
#define TAG_5F28_ISSUER_COUNTRY_CODE 0x5F28

/**
 * Transaction Currency Code <p> Indicates the currency code of the transaction according to
 * ISO 4217
 */
#define TAG_5F2A_TRANSACTION_CURRENCY_CODE 0x5F2A

/**
 * Language Preference <p> 1-4 languages stored in order of preference, each represented by 2
 * alphabetical characters according to ISO 639Note: EMVCo strongly recommends that cards be
 * personalised with data element '5F2D' coded in lowercase, but that terminals accept the data
 * element whether it is coded in upper or lower case.
 */
#define TAG_5F2D_LANGUAGE_PREFERENCE 0x5F2D

/**
 * Service Code <p> Service code as defined in ISO/IEC 7813 for Track 1 and Track 2
 */
#define TAG_5F30_SERVICE_CODE 0x5F30

/**
 * Application Primary Account Number (PAN) Sequence Number (PSN) <p> Identifies and
 * differentiates cards with the same Application PAN
 */
#define TAG_5F34_APPLICATION_PRIMARY_ACCOUNT_NUMBER_SEQUENCE_NUMBER 0x5F34

/**
 * Transaction Currency Exponent <p> Identifies the decimal point position from the right of
 * the transaction amount according to ISO 4217
 */
#define TAG_5F36_TRANSACTION_CURRENCY_EXPONENT 0x5F36

/**
 * Transaction Reference Currency Code <p> Identifies the common currency used by the terminal
 */
#define TAG_5F3C_TRANSACTION_REFERENCE_CURRENCY_CODE 0x5F3C

/**
 * Transaction Reference Currency Exponent <p> Identifies the decimal point position from the
 * right of the terminal common currency
 */
#define TAG_5F3D_TRANSACTION_REFERENCE_CURRENCY_EXPONENT 0x5F3D

/**
 * Issuer URL <p> The URL provides the location of the Issuer's Library Server on the Internet.
 */
#define TAG_5F50_ISSUER_URL 0x5F50

/**
 * International Bank Account Number (IBAN) <p> Uniquely identifies the account of a customer
 * at a financial institution as defined in ISO 13616.
 */
#define TAG_5F53_INTERNATIONAL_BANK_ACCOUNT_NUMBER 0x5F53

/**
 * Bank Identifier Code (BIC) <p> Uniquely identifies a bank as defined in ISO 9362.
 */
#define TAG_5F54_BANK_IDENTIFIER_CODE 0x5F54

/**
 * Issuer Country Code (alpha2 format) <p> Indicates the country of the issuer as defined in
 * ISO 3166 (using a 2 character alphabetic code)
 */
#define TAG_5F55_ISSUER_COUNTRY_CODE 0x5F55

/**
 * Issuer Country Code (alpha3 format) <p> Indicates the country of the issuer as defined in
 * ISO 3166 (using a 3 character alphabetic code)
 */
#define TAG_5F56_ISSUER_COUNTRY_CODE 0x5F56

/**
 * Account Type <p> Indicates the type of account selected on the terminal, coded as specified
 * in Annex G
 */
#define TAG_5F57_ACCOUNT_TYPE 0x5F57

/**
 * Application Template <p> Template containing one or more data objects relevant to an
 * application directory entry according to [ISO 7816-5].
 */
#define TAG_61_APPLICATION_TEMPLATE 0x61

/**
 * File Control Parameters (FCP) Template <p> Identifies the FCP template according to ISO/IEC
 * 7816-4
 */
#define TAG_62_FILE_CONTROL_PARAMETERS_TEMPLATE 0x62

/**
 * File Control Information (FCI) Template <p> Identifies the FCI template according to ISO/IEC
 * 7816-4
 */
#define TAG_6F_FILE_CONTROL_INFORMATION_TEMPLATE 0x6F

/**
 * READ RECORD Response Message Template <p> Template containing the data objects returned by
 * the Card in response to a READ RECORD command. Contains the contents of the record read.
 * (Mandatory for SFIs 1-10. Response messages for SFIs 11-30 are outside the scope of EMV, but
 * may use template '70')
 */
#define TAG_70_READ_RECORD_RESPONSE_MESSAGE_TEMPLATE 0x70

/**
 * Issuer Script Template 1 <p> Contains proprietary issuer data for transmission to the ICC
 * before the second GENERATE AC command
 */
#define TAG_71_ISSUER_SCRIPT_TEMPLATE_1 0x71

/**
 * Issuer Script Template 2 <p> Contains proprietary issuer data for transmission to the ICC
 * after the second GENERATE AC command
 */
#define TAG_72_ISSUER_SCRIPT_TEMPLATE_2 0x72

/**
 * Directory Discretionary Template <p> Issuer discretionary part of the directory according to
 * ISO/IEC 7816-5
 */
#define TAG_73_DIRECTORY_DISCRETIONARY_TEMPLATE 0x73

/**
 * Response Message Template Format 2 <p> Contains the data objects (with tags and lengths)
 * returned by the ICC in response to a command
 */
#define TAG_77_RESPONSE_MESSAGE_TEMPLATE_FORMAT_2 0x77

/**
 * Response Message Template Format 1 <p> Contains the data objects (without tags and lengths)
 * returned by the ICC in response to a command
 */
#define TAG_80_RESPONSE_MESSAGE_TEMPLATE_FORMAT_1 0x80

/**
 * Amount, Authorised (Binary) <p> Authorised amount of the transaction (excluding adjustments)
 */
#define TAG_81_AMOUNT_AUTHORISED 0x81

/**
 * Application Interchange Profile (AIP) <p> Indicates the capabilities of the card to support
 * specific functions in the application
 */
#define TAG_82_APPLICATION_INTERCHANGE_PROFILE 0x82

/**
 * Command Template <p> Identifies the data field of a command message
 */
#define TAG_83_COMMAND_TEMPLATE 0x83

/**
 * Dedicated File (DF) Name <p> Identifies the name of the DF as described in ISO/IEC 7816-4
 */
#define TAG_84_DEDICATED_FILE_NAME 0x84

/**
 * Issuer Script Command <p> Contains a command for transmission to the ICC
 */
#define TAG_86_ISSUER_SCRIPT_COMMAND 0x86

/**
 * Application Priority Indicator <p> Indicates the priority of a given application or group of
 * applications in a directory
 */
#define TAG_87_APPLICATION_PRIORITY_INDICATOR 0x87

/**
 * Short File Identifier (SFI) <p> Identifies the AEF referenced in commands related to a given
 * ADF or DDF. It is a binary data object having a value in the range 1 to 30 and with the three
 * high order bits set to zero.
 */
#define TAG_88_SHORT_FILE_IDENTIFIER 0x88

/**
 * Authorization Code <p> Nonzero value generated by the issuer for an approved transaction.
 */
#define TAG_89_AUTHORISATION_CODE 0x89

/**
 * Authorization Response Code (ARC) <p> Indicates the transaction disposition of the
 * transaction received from the issuer for online authorizations.
 */
#define TAG_8A_AUTHORISATION_RESPONSE_CODE 0x8A

/**
 * Card Risk Management Data Object List 1 (CDOL1) <p> List of data objects (tag and length) to
 * be passed to the ICC in the first GENERATE AC command
 */
#define TAG_8C_CARD_RISK_MANAGEMENT_DATA_OBJECT_LIST_1 0x8C

/**
 * Card Risk Management Data Object List 2 (CDOL2) <p> List of data objects (tag and length) to
 * be passed to the ICC in the second GENERATE AC command
 */
#define TAG_8D_CARD_RISK_MANAGEMENT_DATA_OBJECT_LIST_2 0x8D

/**
 * Cardholder Verification Method (CVM) List <p> Identifies a method of verification of the
 * cardholder supported by the application
 */
#define TAG_8E_CARDHOLDER_VERIFICATION_METHOD_LIST 0x8E

/**
 * Certification Authority Public Key Index (PKI) <p> Identifies the certification authority's
 * public key in conjunction with the RID
 */
#define TAG_8F_CERTIFICATION_AUTHORITY_PUBLIC_KEY_INDEX 0x8F

/**
 * Issuer Public Key Certificate <p> Issuer public key certified by a certification authority
 */
#define TAG_90_ISSUER_PUBLIC_KEY_CERTIFICATE 0x90

/**
 * Issuer Authentication Data <p> Data sent to the ICC for online Issuer Authentication
 */
#define TAG_91_ISSUER_AUTHENTICATION_DATA 0x91

/**
 * Issuer Public Key Remainder <p> Remaining digits of the Issuer Public Key Modulus
 */
#define TAG_92_ISSUER_PUBLIC_KEY_REMAINDER 0x92

/**
 * Signed Application Data <p> Digital signature on critical application parameters that is
 * used in static data authentication (SDA).
 */
#define TAG_93_SIGNED_APPLICATION_DATA 0x93

/**
 * Application File Locator (AFL) <p> Indicates the location (SFI range of records) of the
 * Application Elementary Files associated with a particular AID, and read by the Kernel during
 * a transaction.
 */
#define TAG_94_APPLICATION_FILE_LOCATOR 0x94

/**
 * Terminal Verification Results (TVR) <p> Status of the different functions as seen from the
 * terminal
 */
#define TAG_95_TERMINAL_VERIFICATION_RESULTS 0x95

/**
 * Transaction Certificate Data Object List (TDOL) <p> List of data objects (tag and length) to
 * be used by the terminal in generating the TC Hash Value
 */
#define TAG_97_TRANSACTION_CERTIFICATE_DATA_OBJECT_LIST 0x97

/**
 * Transaction Certificate (TC) Hash Value <p> Result of a hash function specified in Book 2,
 * Annex B3.1
 */
#define TAG_98_TRANSACTION_CERTIFICATE_HASH_VALUE 0x98

/**
 * Transaction Personal Identification Number (PIN) Data <p> Data entered by the cardholder for
 * the purpose of the PIN verification
 */
#define TAG_99_TRANSACTION_PERSONAL_IDENTIFICATION_NUMBER_DATA 0x99

/**
 * Transaction Date <p> Local date that the transaction was authorised
 */
#define TAG_9A_TRANSACTION_DATE 0x9A

/**
 * Transaction Status Information <p> Indicates the functions performed in a transaction
 */
#define TAG_9B_TRANSACTION_STATUS_INFORMATION 0x9B

/**
 * Transaction Type <p> Indicates the type of financial transaction, represented by the first
 * two digits of the ISO 8583:1987 Processing Code. The actual values to be used for the
 * Transaction Type data element are defined by the relevant payment system
 */
#define TAG_9C_TRANSACTION_TYPE 0x9C

/**
 * Directory Definition File (DDF) Name <p> Identifies the name of a DF associated with a
 * directory
 */
#define TAG_9D_DIRECTORY_DEFINITION_FILE_NAME 0x9D

/**
 * Acquirer Identifier <p> Uniquely identifies the acquirer within each payment system
 */
#define TAG_9F01_ACQUIRER_IDENTIFIER 0x9F01

/**
 * Amount, Authorised (Numeric) <p> Authorised amount of the transaction (excluding
 * adjustments)
 */
#define TAG_9F02_AMOUNT_AUTHORISED 0x9F02

/**
 * Amount, Other (Numeric) <p> Secondary amount associated with the transaction representing a
 * cashback amount
 */
#define TAG_9F03_AMOUNT_OTHER 0x9F03

/**
 * Amount, Other (Binary) <p> Secondary amount associated with the transaction representing a
 * cashback amount
 */
#define TAG_9F04_AMOUNT_OTHER 0x9F04

/**
 * Application Discretionary Data <p> Issuer or payment system specified data relating to the
 * application
 */
#define TAG_9F05_APPLICATION_DISCRETIONARY_DATA 0x9F05

/**
 * Application Identifier (AID) - terminal <p> Identifies the application as described in
 * ISO/IEC 7816-5
 */
#define TAG_9F06_APPLICATION_IDENTIFIER__TERMINAL 0x9F06

/**
 * Application Usage Control (AUC) <p> Indicates issuer's specified restrictions on the
 * geographic usage and services allowed for the application
 */
#define TAG_9F07_APPLICATION_USAGE_CONTROL 0x9F07

/**
 * Application Version Number <p> Version number assigned by the payment system for the
 * application in the Card
 */
#define TAG_9F08_APPLICATION_VERSION_NUMBER 0x9F08

/**
 * Application Version Number <p> Version number assigned by the payment system for the Kernel
 * application
 */
#define TAG_9F09_APPLICATION_VERSION_NUMBER 0x9F09

/**
 * Cardholder Name Extended <p> Indicates the whole cardholder name when greater than 26
 * characters using the same coding convention as in ISO 7813
 */
#define TAG_9F0B_CARDHOLDER_NAME_EXTENDED 0x9F0B

/**
 * Issuer Action Code - Default <p> Specifies the issuer's conditions that cause a transaction
 * to be rejected if it might have been approved online, but the terminal is unable to process
 * the transaction online
 */
#define TAG_9F0D_ISSUER_ACTION_CODE_DEFAULT 0x9F0D

/**
 * Issuer Action Code - Denial <p> Specifies the issuer's conditions that cause the denial of a
 * transaction without attempt to go online
 */
#define TAG_9F0E_ISSUER_ACTION_CODE_DENIAL 0x9F0E

/**
 * Issuer Action Code - Online <p> Specifies the issuer's conditions that cause a transaction
 * to be transmitted online
 */
#define TAG_9F0F_ISSUER_ACTION_CODE_ONLINE 0x9F0F

/**
 * Issuer Application Data (IAD) <p> Contains proprietary application data for transmission to
 * the issuer in an online transaction. Note: For CCD-compliant applications, Annex C, section
 * C7 defines the specific coding of the Issuer Application Data (IAD). To avoid potential
 * conflicts with CCD-compliant applications, it is strongly recommended that the IAD data
 * element in an application that is not CCD-compliant should not use the coding for a
 * CCD-compliant application.
 */
#define TAG_9F10_ISSUER_APPLICATION_DATA 0x9F10

/**
 * Issuer Code Table Index <p> Indicates the code table according to ISO/IEC 8859 for
 * displaying the Application Preferred Name
 */
#define TAG_9F11_ISSUER_CODE_TABLE_INDEX 0x9F11

/**
 * Application Preferred Name <p> Preferred mnemonic associated with the AID
 */
#define TAG_9F12_APPLICATION_PREFERRED_NAME 0x9F12

/**
 * Last Online Application Transaction Counter (ATC) Register <p> ATC value of the last
 * transaction that went online
 */
#define TAG_9F13_LAST_ONLINE_APPLICATION_TRANSACTION_COUNTER_REGISTER 0x9F13

/**
 * Lower Consecutive Offline Limit <p> Issuer-specified preference for the maximum number of
 * consecutive offline transactions for this ICC application allowed in a terminal with online
 * capability
 */
#define TAG_9F14_LOWER_CONSECUTIVE_OFFLINE_LIMIT 0x9F14

/**
 * Merchant Category Code <p> Classifies the type of business being done by the merchant,
 * represented according to ISO 8583:1993 for Card Acceptor Business Code
 */
#define TAG_9F15_MERCHANT_CATEGORY_CODE 0x9F15

/**
 * Merchant Identifier <p> When concatenated with the Acquirer Identifier, uniquely identifies
 * a given merchant
 */
#define TAG_9F16_MERCHANT_IDENTIFIER 0x9F16

/**
 * Personal Identification Number (PIN) Try Counter <p> Number of PIN tries remaining
 */
#define TAG_9F17_PERSONAL_IDENTIFICATION_NUMBER_TRY_COUNTER 0x9F17

/**
 * Issuer Script Identifier <p> May be sent in authorization response from issuer when response
 * contains Issuer Script. Assigned by the issuer to uniquely identify the Issuer Script.
 */
#define TAG_9F18_ISSUER_SCRIPT_IDENTIFIER 0x9F18

/**
 * Deleted (see 9F49) <p> В
 */
#define TAG_9F19_DELETED 0x9F19

/**
 * Terminal Country Code <p> Indicates the country of the terminal, represented according to
 * ISO 3166
 */
#define TAG_9F1A_TERMINAL_COUNTRY_CODE 0x9F1A

/**
 * Terminal Floor Limit <p> Indicates the floor limit in the terminal in conjunction with the
 * AID
 */
#define TAG_9F1B_TERMINAL_FLOOR_LIMIT 0x9F1B

/**
 * Terminal Identification <p> Designates the unique location of a Terminal at a merchant
 */
#define TAG_9F1C_TERMINAL_IDENTIFICATION 0x9F1C

/**
 * Terminal Risk Management Data <p> Application-specific value used by the card for risk
 * management purposes
 */
#define TAG_9F1D_TERMINAL_RISK_MANAGEMENT_DATA 0x9F1D

/**
 * Interface Device (IFD) Serial Number <p> Unique and permanent serial number assigned to the
 * IFD by the manufacturer
 */
#define TAG_9F1E_INTERFACE_DEVICE_SERIAL_NUMBER 0x9F1E

/**
 * Track 1 Discretionary Data <p> Discretionary part of track 1 according to ISO/IEC 7813
 */
#define TAG_9F1F_TRACK_1_DISCRETIONARY_DATA 0x9F1F

/**
 * Track 2 Discretionary Data <p> Discretionary part of track 2 according to ISO/IEC 7813
 */
#define TAG_9F20_TRACK_2_DISCRETIONARY_DATA 0x9F20

/**
 * Transaction Time <p> Local time at which the transaction was performed.
 */
#define TAG_9F21_TRANSACTION_TIME 0x9F21

/**
 * Certification Authority Public Key Index (PKI) <p> Identifies the Certificate Authority's
 * public key in conjunction with the RID for use in offline static and dynamic data
 * authentication.
 */
#define TAG_9F22_CERTIFICATION_AUTHORITY_PUBLIC_KEY_INDEX 0x9F22

/**
 * Upper Consecutive Offline Limit <p> Issuer-specified preference for the maximum number of
 * consecutive offline transactions for this ICC application allowed in a terminal without
 * online capability
 */
#define TAG_9F23_UPPER_CONSECUTIVE_OFFLINE_LIMIT 0x9F23

/**
 * Application Cryptogram (AC) <p> Cryptogram returned by the ICC in response of the GENERATE
 * AC or RECOVER AC command
 */
#define TAG_9F26_APPLICATION_CRYPTOGRAM 0x9F26

/**
 * Cryptogram Information Data (CID) <p> Indicates the type of cryptogram and the actions to be
 * performed by the terminal
 */
#define TAG_9F27_CRYPTOGRAM_INFORMATION_DATA 0x9F27

/**
 * Extended Selection <p> The value to be appended to the ADF Name in the data field of the
 * SELECT command, if the Extended Selection Support flag is present and set to 1. Content is
 * payment system proprietary.
 */
#define TAG_9F29_EXTENDED_SELECTION 0x9F29

/**
 * Kernel Identifier <p> Indicates the card's preference for the kernel on which the
 * contactless application can be processed.
 */
#define TAG_9F2A_KERNEL_IDENTIFIER 0x9F2A

/**
 * Integrated Circuit Card (ICC) PIN Encipherment Public Key Certificate <p> ICC PIN
 * Encipherment Public Key certified by the issuer
 */
#define TAG_9F2D_INTEGRATED_CIRCUIT_CARD_PIN_ENCIPHERMENT_PUBLIC_KEY_CERTIFICATE 0x9F2D

/**
 * Integrated Circuit Card (ICC) PIN Encipherment Public Key Exponent <p> ICC PIN Encipherment
 * Public Key Exponent used for PIN encipherment
 */
#define TAG_9F2E_INTEGRATED_CIRCUIT_CARD_PIN_ENCIPHERMENT_PUBLIC_KEY_EXPONENT 0x9F2E

/**
 * Integrated Circuit Card (ICC) PIN Encipherment Public Key Remainder <p> Remaining digits of
 * the ICC PIN Encipherment Public Key Modulus
 */
#define TAG_9F2F_INTEGRATED_CIRCUIT_CARD_PIN_ENCIPHERMENT_PUBLIC_KEY_REMAINDER 0x9F2F

/**
 * Issuer Public Key Exponent <p> Issuer public key exponent used for the verification of the
 * Signed Static Application Data and the ICC Public Key Certificate
 */
#define TAG_9F32_ISSUER_PUBLIC_KEY_EXPONENT 0x9F32

/**
 * Terminal Capabilities <p> Indicates the card data input, CVM, and security capabilities of
 * the Terminal and Reader. The CVM capability (Byte 2) is instantiated with values depending on
 * the transaction amount. The Terminal Capabilities is coded according to Annex A.2 of [EMV
 * Book 4].
 */
#define TAG_9F33_TERMINAL_CAPABILITIES 0x9F33

/**
 * Cardholder Verification Method (CVM) Results <p> Indicates the results of the last CVM
 * performed
 */
#define TAG_9F34_CARDHOLDER_VERIFICATION_METHOD_RESULTS 0x9F34

/**
 * Terminal Type <p> Indicates the environment of the terminal, its communications capability,
 * and its operational control
 */
#define TAG_9F35_TERMINAL_TYPE 0x9F35

/**
 * Application Transaction Counter (ATC) <p> Counter maintained by the application in the ICC
 * (incrementing the ATC is managed by the ICC)
 */
#define TAG_9F36_APPLICATION_TRANSACTION_COUNTER 0x9F36

/**
 * Unpredictable Number (UN) <p> Value to provide variability and uniqueness to the generation
 * of a cryptogram
 */
#define TAG_9F37_UNPREDICTABLE_NUMBER 0x9F37

/**
 * Processing Options Data Object List (PDOL) <p> Contains a list of terminal resident data
 * objects (tags and lengths) needed by the ICC in processing the GET PROCESSING OPTIONS command
 */
#define TAG_9F38_PROCESSING_OPTIONS_DATA_OBJECT_LIST 0x9F38

/**
 * Point-of-Service (POS) Entry Mode <p> Indicates the method by which the PAN was entered,
 * according to the first two digits of the ISO 8583:1987 POS Entry Mode
 */
#define TAG_9F39_POINTOFSERVICE_ENTRY_MODE 0x9F39

/**
 * Amount, Reference Currency <p> Authorised amount expressed in the reference currency
 */
#define TAG_9F3A_AMOUNT_REFERENCE_CURRENCY 0x9F3A

/**
 * Application Reference Currency <p> 1-4 currency codes used between the terminal and the ICC
 * when the Transaction Currency Code is different from the Application Currency Code each code
 * is 3 digits according to ISO 4217
 */
#define TAG_9F3B_APPLICATION_REFERENCE_CURRENCY 0x9F3B

/**
 * Transaction Reference Currency Code <p> Code defining the common currency used by the
 * terminal in case the Transaction Currency Code is different from the Application Currency
 * Code
 */
#define TAG_9F3C_TRANSACTION_REFERENCE_CURRENCY_CODE 0x9F3C

/**
 * Transaction Reference Currency Exponent <p> Indicates the implied position of the decimal
 * point from the right of the transaction amount, with the Transaction Reference Currency Code
 * represented according to ISO 4217
 */
#define TAG_9F3D_TRANSACTION_REFERENCE_CURRENCY_EXPONENT 0x9F3D

/**
 * Additional Terminal Capabilities <p> Indicates the data input and output capabilities of the
 * Terminal and Reader. The Additional Terminal Capabilities is coded according to Annex A.3 of
 * [EMV Book 4].
 */
#define TAG_9F40_ADDITIONAL_TERMINAL_CAPABILITIES 0x9F40

/**
 * Transaction Sequence Counter <p> Counter maintained by the terminal that is incremented by
 * one for each transaction
 */
#define TAG_9F41_TRANSACTION_SEQUENCE_COUNTER 0x9F41

/**
 * Application Currency Code <p> Indicates the currency in which the account is managed
 * according to ISO 4217
 */
#define TAG_9F42_APPLICATION_CURRENCY_CODE 0x9F42

/**
 * Application Reference Currency Exponent <p> Indicates the implied position of the decimal
 * point from the right of the amount, for each of the 1-4 reference currencies represented
 * according to ISO 4217
 */
#define TAG_9F43_APPLICATION_REFERENCE_CURRENCY_EXPONENT 0x9F43

/**
 * Application Currency Exponent <p> Indicates the implied position of the decimal point from
 * the right of the amount represented according to ISO 4217
 */
#define TAG_9F44_APPLICATION_CURRENCY_EXPONENT 0x9F44

/**
 * Data Authentication Code <p> An issuer assigned value that is retained by the terminal
 * during the verification process of the Signed Static Application Data
 */
#define TAG_9F45_DATA_AUTHENTICATION_CODE 0x9F45

/**
 * Integrated Circuit Card (ICC) Public Key Certificate <p> ICC Public Key certified by the
 * issuer
 */
#define TAG_9F46_INTEGRATED_CIRCUIT_CARD_PUBLIC_KEY_CERTIFICATE 0x9F46

/**
 * Integrated Circuit Card (ICC) Public Key Exponent <p> Exponent ICC Public Key Exponent used
 * for the verification of the Signed Dynamic Application Data
 */
#define TAG_9F47_INTEGRATED_CIRCUIT_CARD_PUBLIC_KEY_EXPONENT 0x9F47

/**
 * Integrated Circuit Card (ICC) Public Key Remainder <p> Remaining digits of the ICC Public
 * Key Modulus
 */
#define TAG_9F48_INTEGRATED_CIRCUIT_CARD_PUBLIC_KEY_REMAINDER 0x9F48

/**
 * Dynamic Data Authentication Data Object List (DDOL) <p> List of data objects (tag and
 * length) to be passed to the ICC in the INTERNAL AUTHENTICATE command
 */
#define TAG_9F49_DYNAMIC_DATA_AUTHENTICATION_DATA_OBJECT_LIST 0x9F49

/**
 * Static Data Authentication Tag List (SDA) <p> List of tags of primitive data objects defined
 * in this specification whose value fields are to be included in the Signed Static or Dynamic
 * Application Data
 */
#define TAG_9F4A_STATIC_DATA_AUTHENTICATION_TAG_LIST 0x9F4A

/**
 * Signed Dynamic Application Data (SDAD) <p> Digital signature on critical application
 * parameters for CDA
 */
#define TAG_9F4B_SIGNED_DYNAMIC_APPLICATION_DATA 0x9F4B

/**
 * ICC Dynamic Number <p> Time-variant number generated by the ICC, to be captured by the
 * terminal
 */
#define TAG_9F4C_ICC_DYNAMIC_NUMBER 0x9F4C

/**
 * Log Entry <p> Provides the SFI of the Transaction Log file and its number of records
 */
#define TAG_9F4D_LOG_ENTRY 0x9F4D

/**
 * Merchant Name and Location <p> Indicates the name and location of the merchant
 */
#define TAG_9F4E_MERCHANT_NAME_AND_LOCATION 0x9F4E

/**
 * Log Format <p> List (in tag and length format) of data objects representing the logged data
 * elements that are passed to the terminal when a transaction log record is read
 */
#define TAG_9F4F_LOG_FORMAT 0x9F4F

/**
 * Offline Accumulator Balance <p> Represents the amount of offline spending available in the
 * Card. The Offline Accumulator Balance is retrievable by the GET DATA command, if allowed by
 * the Card configuration.
 */
#define TAG_9F50_OFFLINE_ACCUMULATOR_BALANCE 0x9F50

/**
 * Application Currency Code <p> В
 */
#define TAG_9F51_APPLICATION_CURRENCY_CODE 0x9F51

/**
 * Application Default Action (ADA) <p> В
 */
#define TAG_9F52_APPLICATION_DEFAULT_ACTION 0x9F52

/**
 * Consecutive Transaction Counter International Limit (CTCIL) <p> В
 */
#define TAG_9F53_CONSECUTIVE_TRANSACTION_COUNTER_INTERNATIONAL_LIMIT 0x9F53

/**
 * Cumulative Total Transaction Amount Limit (CTTAL) <p> В
 */
#define TAG_9F54_CUMULATIVE_TOTAL_TRANSACTION_AMOUNT_LIMIT 0x9F54

/**
 * Geographic Indicator <p> В
 */
#define TAG_9F55_GEOGRAPHIC_INDICATOR 0x9F55

/**
 * Issuer Authentication Indicator <p> В
 */
#define TAG_9F56_ISSUER_AUTHENTICATION_INDICATOR 0x9F56

/**
 * Issuer Country Code <p> В
 */
#define TAG_9F57_ISSUER_COUNTRY_CODE 0x9F57

/**
 * Consecutive Transaction Counter Limit (CTCL) <p> В
 */
#define TAG_9F58_CONSECUTIVE_TRANSACTION_COUNTER_LIMIT 0x9F58

/**
 * Consecutive Transaction Counter Upper Limit (CTCUL) <p> В
 */
#define TAG_9F59_CONSECUTIVE_TRANSACTION_COUNTER_UPPER_LIMIT 0x9F59

/**
 * Application Program Identifier (Program ID) <p> Payment system proprietary data element
 * identifying the Application Program ID of the card application. When personalised, the
 * Application Program ID is returned in the FCI Issuer Discretionary Data of the SELECT
 * response (Tag 'BF0C'). EMV mode readers that support Dynamic Reader Limits (DRL)
 * functionality examine the Application Program ID to determine the Reader Limit Set to apply.
 */
#define TAG_9F5A_APPLICATION_PROGRAM_IDENTIFIER 0x9F5A

/**
 * Issuer Script Results <p> Indicates the results of Issuer Script processing. When the
 * reader/terminal transmits this data element to the acquirer, in this version of Kernel 3, it
 * is acceptable that only byte 1 is transmitted, although it is preferable for all five bytes
 * to be transmitted.
 */
#define TAG_9F5B_ISSUER_SCRIPT_RESULTS 0x9F5B

/**
 * Cumulative Total Transaction Amount Upper Limit (CTTAUL) <p> Visa proprietary data element
 * specifying the maximum total amount of offline transactions in the designated currency or
 * designated and secondary currency allowed for the card application before a transaction is
 * declined after an online transaction is unable to be performed.
 */
#define TAG_9F5C_CUMULATIVE_TOTAL_TRANSACTION_AMOUNT_UPPER_LIMIT 0x9F5C

/**
 * Available Offline Spending Amount (AOSA) <p> Kernel 3 proprietary data element indicating
 * the remaining amount available to be spent offline. The AOSA is a calculated field used to
 * allow the reader to print or display the amount of offline spend that is available on the
 * card.
 */
#define TAG_9F5D_AVAILABLE_OFFLINE_SPENDING_AMOUNT 0x9F5D

/**
 * Consecutive Transaction International Upper Limit (CTIUL) <p> В
 */
#define TAG_9F5E_CONSECUTIVE_TRANSACTION_INTERNATIONAL_UPPER_LIMIT 0x9F5E

/**
 * DS Slot Availability <p> Contains the Card indication, obtained in the response to the GET
 * PROCESSING OPTIONS command, about the slot type(s) available for data storage.
 */
#define TAG_9F5F_DS_SLOT_AVAILABILITY 0x9F5F

/**
 * CVC3 (Track1) <p> The CVC3 (Track1) is a 2-byte cryptogram returned by the Card in the
 * response to the COMPUTE CRYPTOGRAPHIC CHECKSUM command.
 */
#define TAG_9F60_CVC3 0x9F60

/**
 * CVC3 (Track2) <p> The CVC3 (Track2) is a 2-byte cryptogram returned by the Card in the
 * response to the COMPUTE CRYPTOGRAPHIC CHECKSUM command.
 */
#define TAG_9F61_CVC3 0x9F61

/**
 * PCVC3 (Track1) <p> PCVC3(Track1) indicates to the Kernel the positions in the discretionary
 * data field of the Track 1 Data where the CVC3 (Track1) digits must be copied.
 */
#define TAG_9F62_PCVC3 0x9F62

/**
 * Offline Counter Initial Value <p> В
 */
#define TAG_9F63_OFFLINE_COUNTER_INITIAL_VALUE 0x9F63

/**
 * NATC (Track1) <p> The value of NATC(Track1) represents the number of digits of the
 * Application Transaction Counter to be included in the discretionary data field of Track 1
 * Data.
 */
#define TAG_9F64_NATC 0x9F64

/**
 * PCVC3 (Track2) <p> PCVC3(Track2) indicates to the Kernel the positions in the discretionary
 * data field of the Track 2 Data where the CVC3 (Track2) digits must be copied.
 */
#define TAG_9F65_PCVC3 0x9F65

/**
 * Terminal Transaction Qualifiers (TTQ) <p> Indicates reader capabilities, requirements, and
 * preferences to the card. TTQ byte 2 bits 8-7 are transient values, and reset to zero at the
 * beginning of the transaction. All other TTQ bits are static values, and not modified based on
 * transaction conditions. TTQ byte 3 bit 7 shall be set by the acquirer-merchant to 1b.
 */
#define TAG_9F66_TERMINAL_TRANSACTION_QUALIFIERS 0x9F66

/**
 * MSD Offset <p> В
 */
#define TAG_9F67_MSD_OFFSET 0x9F67

/**
 * Card Additional Processes <p> В
 */
#define TAG_9F68_CARD_ADDITIONAL_PROCESSES 0x9F68

/**
 * Card Authentication Related Data <p> Contains the fDDA Version Number, Card Unpredictable
 * Number, and Card Transaction Qualifiers. For transactions where fDDA is performed, the Card
 * Authentication Related Data is returned in the last record specified by the Application File
 * Locator for that transaction.
 */
#define TAG_9F69_CARD_AUTHENTICATION_RELATED_DATA 0x9F69

/**
 * Unpredictable Number (Numeric) <p> Unpredictable number generated by the Kernel during a
 * mag-stripe mode transaction. The Unpredictable Number (Numeric) is passed to the Card in the
 * data field of the COMPUTE CRYPTOGRAPHIC CHECKSUM command.The 8-nUN most significant digits
 * must be set to zero.
 */
#define TAG_9F6A_UNPREDICTABLE_NUMBER 0x9F6A

/**
 * Card CVM Limit <p> В
 */
#define TAG_9F6B_CARD_CVM_LIMIT 0x9F6B

/**
 * Card Transaction Qualifiers (CTQ) <p> In this version of the specification, used to indicate
 * to the device the card CVM requirements, issuer preferences, and card capabilities.
 */
#define TAG_9F6C_CARD_TRANSACTION_QUALIFIERS 0x9F6C

/**
 * VLP Reset Threshold <p> В
 */
#define TAG_9F6D_VLP_RESET_THRESHOLD 0x9F6D

/**
 * Third Party Data <p> The Third Party Data contains various information, possibly including
 * information from a third party. If present in the Card, the Third Party Data must be returned
 * in a file read using the READ RECORD command or in the File Control Information Template.
 * 'Device Type' is present when the most significant bit of byte 1 of 'Unique Identifier' is
 * set to 0b. In this case, the maximum length of 'Proprietary Data' is 26 bytes. Otherwise it
 * is 28 bytes.
 */
#define TAG_9F6E_THIRD_PARTY_DATA 0x9F6E

/**
 * DS Slot Management Control <p> Contains the Card indication, obtained in the response to the
 * GET PROCESSING OPTIONS command, about the status of the slot containing data associated to
 * the DS Requested Operator ID.
 */
#define TAG_9F6F_DS_SLOT_MANAGEMENT_CONTROL 0x9F6F

/**
 * Protected Data Envelope 1 <p> The Protected Data Envelopes contain proprietary information
 * from the issuer, payment system or third party. The Protected Data Envelope can be retrieved
 * with the GET DATA command. Updating the Protected Data Envelope with the PUT DATA command
 * requires secure messaging and is outside the scope of this specification.
 */
#define TAG_9F70_PROTECTED_DATA_ENVELOPE_1 0x9F70

/**
 * Protected Data Envelope 2 <p> Same as Protected Data Envelope 1.
 */
#define TAG_9F71_PROTECTED_DATA_ENVELOPE_2 0x9F71

/**
 * Protected Data Envelope 3 <p> Same as Protected Data Envelope 1.
 */
#define TAG_9F72_PROTECTED_DATA_ENVELOPE_3 0x9F72

/**
 * Protected Data Envelope 4 <p> Same as Protected Data Envelope 1.
 */
#define TAG_9F73_PROTECTED_DATA_ENVELOPE_4 0x9F73

/**
 * Protected Data Envelope 5 <p> Same as Protected Data Envelope 1.
 */
#define TAG_9F74_PROTECTED_DATA_ENVELOPE_5 0x9F74

/**
 * Unprotected Data Envelope 1 <p> The Unprotected Data Envelopes contain proprietary
 * information from the issuer, payment system or third party. Unprotected Data Envelopes can be
 * retrieved with the GET DATA command and can be updated with the PUT DATA (CLA='80') command
 * without secure messaging.
 */
#define TAG_9F75_UNPROTECTED_DATA_ENVELOPE_1 0x9F75

/**
 * Unprotected Data Envelope 2 <p> Same as Unprotected Data Envelope 1.
 */
#define TAG_9F76_UNPROTECTED_DATA_ENVELOPE_2 0x9F76

/**
 * Unprotected Data Envelope 3 <p> Same as Unprotected Data Envelope 1.
 */
#define TAG_9F77_UNPROTECTED_DATA_ENVELOPE_3 0x9F77

/**
 * Unprotected Data Envelope 4 <p> Same as Unprotected Data Envelope 1.
 */
#define TAG_9F78_UNPROTECTED_DATA_ENVELOPE_4 0x9F78

/**
 * Unprotected Data Envelope 5 <p> Same as Unprotected Data Envelope 1.
 */
#define TAG_9F79_UNPROTECTED_DATA_ENVELOPE_5 0x9F79

/**
 * VLP Terminal Support Indicator <p> If present indicates offline and/or online support. If
 * absent indicates online only support
 */
#define TAG_9F7A_VLP_TERMINAL_SUPPORT_INDICATOR 0x9F7A

/**
 * VLP Terminal Transaction Limit <p> В
 */
#define TAG_9F7B_VLP_TERMINAL_TRANSACTION_LIMIT 0x9F7B

/**
 * Customer Exclusive Data (CED) <p> Contains data for transmission to the issuer.
 */
#define TAG_9F7C_CUSTOMER_EXCLUSIVE_DATA 0x9F7C

/**
 * DS Summary 1 <p> Contains the Card indication, obtained in the response to the GET
 * PROCESSING OPTIONS command, about either the stored summary associated with DS ODS Card if
 * present, or about a default zero-filled summary if DS ODS Card is not present and DS
 * Unpredictable Number is present.
 */
#define TAG_9F7D_DS_SUMMARY_1 0x9F7D

/**
 * Mobile Support Indicator <p> The Mobile Support Indicator informs the Card that the Kernel
 * supports extensions for mobile and requires on device cardholder verification.
 */
#define TAG_9F7E_MOBILE_SUPPORT_INDICATOR 0x9F7E

/**
 * DS Unpredictable Number <p> Contains the Card challenge (random), obtained in the response
 * to the GET PROCESSING OPTIONS command, to be used by the Terminal in the summary calculation
 * when providing DS ODS Term.
 */
#define TAG_9F7F_DS_UNPREDICTABLE_NUMBER 0x9F7F

/**
 * File Control Information (FCI) Proprietary Template <p> Identifies the data object
 * proprietary to this specification in the FCI template according to ISO/IEC 7816-4
 */
#define TAG_A5_FILE_CONTROL_INFORMATION_PROPRIETARY_TEMPLATE 0xA5

/**
 * File Control Information (FCI) Issuer Discretionary Data <p> Issuer discretionary part of
 * the File Control Information Proprietary Template.
 */
#define TAG_BF0C_FILE_CONTROL_INFORMATION_ISSUER_DISCRETIONARY_DATA 0xBF0C

/**
 * Visa Fleet - CDO <p> В
 */
#define TAG_BF50_VISA_FLEET_CDO 0xBF50

/**
 * Integrated Data Storage Record Update Template <p> Part of the command data for the EXTENDED
 * GET PROCESSING OPTIONS command. The IDS Record Update Template contains data to be updated in
 * one or more IDS Records.
 */
#define TAG_BF60_INTEGRATED_DATA_STORAGE_RECORD_UPDATE_TEMPLATE 0xBF60

/**
 * Card issuer action code -decline <p> В
 */
#define TAG_C3_CARD_ISSUER_ACTION_CODE_DECLINE 0xC3

/**
 * Card issuer action code -default <p> В
 */
#define TAG_C4_CARD_ISSUER_ACTION_CODE_DEFAULT 0xC4

/**
 * Card issuer action code online <p> В
 */
#define TAG_C5_CARD_ISSUER_ACTION_CODE_ONLINE 0xC5

/**
 * PIN Try Limit <p> В
 */
#define TAG_C6_PIN_TRY_LIMIT 0xC6

/**
 * CDOL 1 Related Data Length <p> В
 */
#define TAG_C7_CDOL_1_RELATED_DATA_LENGTH 0xC7

/**
 * Card risk management country code <p> В
 */
#define TAG_C8_CARD_RISK_MANAGEMENT_COUNTRY_CODE 0xC8

/**
 * Card risk management currency code <p> В
 */
#define TAG_C9_CARD_RISK_MANAGEMENT_CURRENCY_CODE 0xC9

/**
 * Lower cummulative offline transaction amount <p> В
 */
#define TAG_CA_LOWER_CUMMULATIVE_OFFLINE_TRANSACTION_AMOUNT 0xCA

/**
 * Upper cumulative offline transaction amount <p> В
 */
#define TAG_CB_UPPER_CUMULATIVE_OFFLINE_TRANSACTION_AMOUNT 0xCB

/**
 * Card Issuer Action Code (PayPass) - Default <p> В
 */
#define TAG_CD_CARD_ISSUER_ACTION_CODE__DEFAULT 0xCD

/**
 * Card Issuer Action Code (PayPass) - Online <p> В
 */
#define TAG_CE_CARD_ISSUER_ACTION_CODE__ONLINE 0xCE

/**
 * Card Issuer Action Code (PayPass) - Decline <p> В
 */
#define TAG_CF_CARD_ISSUER_ACTION_CODE__DECLINE 0xCF

/**
 * Currency conversion table <p> В
 */
#define TAG_D1_CURRENCY_CONVERSION_TABLE 0xD1

/**
 * Integrated Data Storage Directory (IDSD) <p> Directory of Integrated Data Storage records on
 * the card.
 */
#define TAG_D2_INTEGRATED_DATA_STORAGE_DIRECTORY 0xD2

/**
 * Additional check table <p> В
 */
#define TAG_D3_ADDITIONAL_CHECK_TABLE 0xD3

/**
 * Application Control <p> В
 */
#define TAG_D5_APPLICATION_CONTROL 0xD5

/**
 * Default ARPC response code <p> В
 */
#define TAG_D6_DEFAULT_ARPC_RESPONSE_CODE 0xD6

/**
 * Application Control (PayPass) <p> В
 */
#define TAG_D7_APPLICATION_CONTROL 0xD7

/**
 * AIP (PayPass) <p> В
 */
#define TAG_D8_AIP 0xD8

/**
 * AFL (PayPass) <p> В
 */
#define TAG_D9_AFL 0xD9

/**
 * Static CVC3-TRACK1 <p> В
 */
#define TAG_DA_STATIC_CVC3TRACK1 0xDA

/**
 * Static CVC3-TRACK2 <p> В
 */
#define TAG_DB_STATIC_CVC3TRACK2 0xDB

/**
 * IVCVC3-TRACK1 <p> В
 */
#define TAG_DC_IVCVC3TRACK1 0xDC

/**
 * IVCVC3-TRACK2 <p> В
 */
#define TAG_DD_IVCVC3TRACK2 0xDD

/**
 * Encrypted PIN Block in Tag 9F62 - ISO 95641 Format 0 <p> В
 */
#define TAG_DF01_ENCRYPTED_PIN_BLOCK_IN_TAG_9F62_ISO_95641_FORMAT_0 0xDF01

/**
 * PEK Version Number <p> В
 */
#define TAG_DF02_PEK_VERSION_NUMBER 0xDF02

/**
 * PIN Try Limit <p> В
 */
#define TAG_DF03_PIN_TRY_LIMIT 0xDF03

/**
 * PIN Try Counter (VSDC Application) <p> В
 */
#define TAG_DF04_PIN_TRY_COUNTER 0xDF04

/**
 * AIP - For VISA Contactless <p> В
 */
#define TAG_DF05_AIP_FOR_VISA_CONTACTLESS 0xDF05

/**
 * Products permitted <p> В
 */
#define TAG_DF06_PRODUCTS_PERMITTED 0xDF06

/**
 * Offline checks mandated <p> В
 */
#define TAG_DF07_OFFLINE_CHECKS_MANDATED 0xDF07

/**
 * UDKmac <p> В
 */
#define TAG_DF08_UDKMAC 0xDF08

/**
 * UDKenc <p> В
 */
#define TAG_DF09_UDKENC 0xDF09

/**
 * Retries Permitted Limit <p> В
 */
#define TAG_DF0B_RETRIES_PERMITTED_LIMIT 0xDF0B

/**
 * Script Message Update <p> В
 */
#define TAG_DF0C_SCRIPT_MESSAGE_UPDATE 0xDF0C

/**
 * Fleet Issuer Action Code - Default <p> В
 */
#define TAG_DF0D_FLEET_ISSUER_ACTION_CODE_DEFAULT 0xDF0D

/**
 * Fleet Issuer Action Code - Denial <p> В
 */
#define TAG_DF0E_FLEET_ISSUER_ACTION_CODE_DENIAL 0xDF0E

/**
 * Fleet Issuer Action Code - Online <p> В
 */
#define TAG_DF0F_FLEET_ISSUER_ACTION_CODE_ONLINE 0xDF0F

/**
 * Vehicle Registration Number <p> В
 */
#define TAG_DF12_VEHICLE_REGISTRATION_NUMBER 0xDF12

/**
 * DDA Public Modulus <p> В
 */
#define TAG_DF13_DDA_PUBLIC_MODULUS 0xDF13

/**
 * Driver Name <p> В
 */
#define TAG_DF14_DRIVER_NAME 0xDF14

/**
 * Driver ID <p> В
 */
#define TAG_DF15_DRIVER_ID 0xDF15

/**
 * Max Fill Volume <p> В
 */
#define TAG_DF16_MAX_FILL_VOLUME 0xDF16

/**
 * DDA Public Modulus Length <p> В
 */
#define TAG_DF17_DDA_PUBLIC_MODULUS_LENGTH 0xDF17

/**
 * Mileage <p> В
 */
#define TAG_DF18_MILEAGE 0xDF18

/**
 * Issuer Proprietary Bitmap (IPB) <p> В
 */
#define TAG_DF20_ISSUER_PROPRIETARY_BITMAP 0xDF20

/**
 * Internet Authentication Flag (IAF) <p> В
 */
#define TAG_DF21_INTERNET_AUTHENTICATION_FLAG 0xDF21

/**
 * Encrypted PEK - RFU <p> В
 */
#define TAG_DF22_ENCRYPTED_PEK_RFU 0xDF22

/**
 * PEK Key Check Value - RFU <p> В
 */
#define TAG_DF23_PEK_KEY_CHECK_VALUE_RFU 0xDF23

/**
 * MDK - Key derivation Index <p> В
 */
#define TAG_DF24_MDK_KEY_DERIVATION_INDEX 0xDF24

/**
 * VISA DPA - MDK - Key derivation Index <p> В
 */
#define TAG_DF25_VISA_DPA_MDK_KEY_DERIVATION_INDEX 0xDF25

/**
 * Encrypted PIN Block - ISO 9564-1 Format 1 PIN Block (Thales P3 Format 05) <p> В
 */
#define TAG_DF26_ENCRYPTED_PIN_BLOCK_ISO_95641_FORMAT_1_PIN_BLOCK 0xDF26

/**
 * qVSDC AIP <p> В
 */
#define TAG_DF40_QVSDC_AIP 0xDF40

/**
 * VSDC AIP <p> В
 */
#define TAG_DF41_VSDC_AIP 0xDF41

/**
 * UDKac <p> В
 */
#define TAG_DF42_UDKAC 0xDF42

/**
 * UDKmac <p> В
 */
#define TAG_DF43_UDKMAC 0xDF43

/**
 * UDKenc <p> В
 */
#define TAG_DF44_UDKENC 0xDF44

/**
 * UDKcvc <p> В
 */
#define TAG_DF47_UDKCVC 0xDF47

/**
 * UDKac KCV <p> В
 */
#define TAG_DF48_UDKAC_KCV 0xDF48

/**
 * UDKmac KCV <p> В
 */
#define TAG_DF49_UDKMAC_KCV 0xDF49

/**
 * UDKenc KCV <p> В
 */
#define TAG_DF4A_UDKENC_KCV 0xDF4A

/**
 * UDKcvc KCV <p> В
 */
#define TAG_DF4B_UDKCVC_KCV 0xDF4B

/**
 * Grand Parent AC <p> В
 */
#define TAG_DF51_GRAND_PARENT_AC 0xDF51

/**
 * Parent AC <p> В
 */
#define TAG_DF52_PARENT_AC 0xDF52

/**
 * Grand Parent MAC <p> В
 */
#define TAG_DF53_GRAND_PARENT_MAC 0xDF53

/**
 * Parent MAC <p> В
 */
#define TAG_DF54_PARENT_MAC 0xDF54

/**
 * Grand Parent ENC <p> В
 */
#define TAG_DF55_GRAND_PARENT_ENC 0xDF55

/**
 * Parent ENC/Terminal Action Code - Default <p> В
 */
#define TAG_DF56_PARENT_ENC_TERMINAL_ACTION_CODE_DEFAULT 0xDF56

/**
 * Terminal Action Code - Decline <p> В
 */
#define TAG_DF57_TERMINAL_ACTION_CODE_DECLINE 0xDF57

/**
 * DS Input (Card) <p> Contains Terminal provided data if permanent data storage in the Card
 * was applicable (DS Slot Management Control[8]=1b), remains applicable, or becomes applicable
 * (DS ODS Info[8]=1b). Otherwise this data item is a filler to be supplied by the Kernel. The
 * data is forwarded to the Card with the GENERATE AC command, as per DSDOL formatting.
 */
#define TAG_DF60_DS_INPUT 0xDF60

/**
 * DDA Component Q <p> В
 */
#define TAG_DF61_DDA_COMPONENT_Q 0xDF61

/**
 * DS ODS Info <p> Contains Terminal provided data to be forwarded to the Card with the
 * GENERATE AC command, as per DSDOL formatting.
 */
#define TAG_DF62_DS_ODS_INFO 0xDF62

/**
 * DDA Component D2 <p> В
 */
#define TAG_DF63_DDA_COMPONENT_D2 0xDF63

/**
 * DDA Component Q Minus 1 Mod P <p> В
 */
#define TAG_DF64_DDA_COMPONENT_Q_MINUS_1_MOD_P 0xDF64

/**
 * DDA Private Exponent <p> В
 */
#define TAG_DF65_DDA_PRIVATE_EXPONENT 0xDF65

/**
 * Paypass Contactless <p> В
 */
#define TAG_DF6B_PAYPASS_CONTACTLESS 0xDF6B

/**
 * Dynamic Data Authentication Keys <p> В
 */
#define TAG_DF79_DYNAMIC_DATA_AUTHENTICATION_KEYS 0xDF79

/**
 * DS Summary 2 <p> This data allows the Kernel to check the consistency between DS Summary 1
 * and DS Summary 2, and so to ensure that DS ODS Card is provided by a genuine Card. It is
 * located in the ICC Dynamic Data recovered from the Signed Dynamic Application Data.
 */
#define TAG_DF8101_DS_SUMMARY_2 0xDF8101

/**
 * DS Summary 3 <p> This data allows the Kernel to check whether the Card has seen the same
 * transaction data as were sent by the Terminal/Kernel. It is located in the ICC Dynamic Data
 * recovered from the Signed Dynamic Application Data.
 */
#define TAG_DF8102_DS_SUMMARY_3 0xDF8102

/**
 * Balance Read Before Gen AC <p> The presence of Balance Read Before Gen AC in the TLV
 * Database is an indication to the Kernel to read the offline balance from the Card before the
 * GENERATE AC command. The Kernel stores the offline balance read from the Card in Balance Read
 * Before Gen AC.
 */
#define TAG_DF8104_BALANCE_READ_BEFORE_GEN_AC 0xDF8104

/**
 * Balance Read After Gen AC <p> The presence of Balance Read After Gen AC in the TLV Database
 * is an indication to the Kernel to read the offline balance from the Card after the GENERATE
 * AC command. The Kernel stores the offline balance read from the Card in Balance Read After
 * Gen AC.
 */
#define TAG_DF8105_BALANCE_READ_AFTER_GEN_AC 0xDF8105

/**
 * Data Needed <p> List of tags included in the DEK signal to request information from the
 * Terminal.
 */
#define TAG_DF8106_DATA_NEEDED 0xDF8106

/**
 * CDOL1 Related Data <p> Command data field of the GENERATE AC command, coded according to
 * CDOL1.
 */
#define TAG_DF8107_CDOL1_RELATED_DATA 0xDF8107

/**
 * DS AC Type <p> Contains the AC type indicated by the Terminal for which IDS data must be
 * stored in the Card.
 */
#define TAG_DF8108_DS_AC_TYPE 0xDF8108

/**
 * DS Input (Term) <p> Contains Terminal provided data if permanent data storage in the Card
 * was applicable (DS Slot Management Control[8]=1b), remains applicable or becomes applicable
 * (DS ODS Info[8]=1b). DS Input (Term) is used by the Kernel as input to calculate DS Digest H.
 */
#define TAG_DF8109_DS_INPUT 0xDF8109

/**
 * DS ODS Info For Reader <p> Contains instructions from the Terminal on how to proceed with
 * the transaction if:- The AC requested by the Terminal does not match the AC proposed by the
 * Kernel- The update of the slot data has failed
 */
#define TAG_DF810A_DS_ODS_INFO_FOR_READER 0xDF810A

/**
 * DS Summary Status <p> Information reported by the Kernel to the Terminal about:- The
 * consistency between DS Summary 1 and DS Summary 2 (successful read)- The difference between
 * DS Summary 2 and DS Summary 3 (successful write)This data object is part of the Discretionary
 * Data.
 */
#define TAG_DF810B_DS_SUMMARY_STATUS 0xDF810B

/**
 * Kernel ID <p> Contains a value that uniquely identifies each Kernel. There is one occurrence
 * of this data object for each Kernel in the Reader.
 */
#define TAG_DF810C_KERNEL_ID 0xDF810C

/**
 * DSVN Term <p> Integrated data storage support by the Kernel depends on the presence of this
 * data object. If it is absent, or is present with a length of zero, integrated data storage is
 * not supported. Its value is '02' for this version of data storage functionality. This
 * variable length data item has an initial byte that defines the maximum version number
 * supported by the Terminal and a variable number of subsequent bytes that define how the
 * Terminal supports earlier versions of the specification. As this is the first version, no
 * legacy support is described and no additional bytes are present.
 */
#define TAG_DF810D_DSVN_TERM 0xDF810D

/**
 * Post-Gen AC Put Data Status <p> Information reported by the Kernel to the Terminal, about
 * the processing of PUT DATA commands after processing the GENERATE AC command. Possible values
 * are 'completed' or 'not completed'. In the latter case, this status is not specific about
 * which of the PUT DATA commands failed, or about how many of these commands have failed or
 * succeeded. This data object is part of the Discretionary Data provided by the Kernel to the
 * Terminal.
 */
#define TAG_DF810E_POSTGEN_AC_PUT_DATA_STATUS 0xDF810E

/**
 * Pre-Gen AC Put Data Status <p> Information reported by the Kernel to the Terminal, about the
 * processing of PUT DATA commands before sending the GENERATE AC command. Possible values are
 * 'completed' or 'not completed'. In the latter case, this status is not specific about which
 * of the PUT DATA commands failed, or about how many of these commands have failed or
 * succeeded. This data object is part of the Discretionary Data provided by the Kernel to the
 * Terminal.
 */
#define TAG_DF810F_PREGEN_AC_PUT_DATA_STATUS 0xDF810F

/**
 * Proceed To First Write Flag <p> Indicates that the Terminal will send no more requests to
 * read data other than as indicated in Tags To Read. This data item indicates the point at
 * which the Kernel shifts from the Card reading phase to the Card writing phase. If Proceed To
 * First Write Flag is not present or is present with non zero length and value different from
 * zero, then the Kernel proceeds without waiting. If Proceed To First Write Flag is present
 * with zero length, then the Kernel sends a DEK signal to the Terminal and waits for the DET
 * signal. If Proceed To First Write Flag is present with non zero length and value equal to
 * zero, then the Kernel waits for a DET signal from the Terminal without sending a DEK signal.
 */
#define TAG_DF8110_PROCEED_TO_FIRST_WRITE_FLAG 0xDF8110

/**
 * PDOL Related Data <p> Command data field of the GET PROCESSING OPTIONS command, coded
 * according to PDOL.
 */
#define TAG_DF8111_PDOL_RELATED_DATA 0xDF8111

/**
 * Tags To Read <p> List of tags indicating the data the Terminal has requested to be read.
 * This data item is present if the Terminal wants any data back from the Card before the Data
 * Record. This could be in the context of SDS, or for non data storage usage reasons, for
 * example the PAN. This data item may contain configured data.This data object may be provided
 * several times by the Terminal. Therefore, the values of each of these tags must be
 * accumulated in the Tags To Read Yet buffer.
 */
#define TAG_DF8112_TAGS_TO_READ 0xDF8112

/**
 * DRDOL Related Data <p> Command data field of the RECOVER AC command, coded according to
 * DRDOL.
 */
#define TAG_DF8113_DRDOL_RELATED_DATA 0xDF8113

/**
 * Reference Control Parameter <p> Working variable to store the reference control parameter of
 * the GENERATE AC command.
 */
#define TAG_DF8114_REFERENCE_CONTROL_PARAMETER 0xDF8114

/**
 * Error Indication <p> Contains information regarding the nature of the error that has been
 * encountered during the transaction processing. This data object is part of the Discretionary
 * Data.
 */
#define TAG_DF8115_ERROR_INDICATION 0xDF8115

/**
 * User Interface Request Data <p> Combines all parameters to be sent with the MSG signal.
 */
#define TAG_DF8116_USER_INTERFACE_REQUEST_DATA 0xDF8116

/**
 * Card Data Input Capability <p> Indicates the card data input capability of the Terminal and
 * Reader. The Card Data Input Capability is coded according to Annex A.2 of [EMV Book 4].
 */
#define TAG_DF8117_CARD_DATA_INPUT_CAPABILITY 0xDF8117

/**
 * CVM Capability - CVM Required <p> Indicates the CVM capability of the Terminal and Reader
 * when the transaction amount is greater than the Reader CVM Required Limit. The CVM Capability
 * - CVM Required is coded according to Annex A.2 of [EMV Book 4].
 */
#define TAG_DF8118_CVM_CAPABILITY_CVM_REQUIRED 0xDF8118

/**
 * CVM Capability - No CVM Required <p> Indicates the CVM capability of the Terminal and Reader
 * when the transaction amount is less than or equal to the Reader CVM Required Limit. The CVM
 * Capability - No CVM Required is coded according to Annex A.2 of [EMV Book 4].
 */
#define TAG_DF8119_CVM_CAPABILITY_NO_CVM_REQUIRED 0xDF8119

/**
 * Default UDOL <p> The Default UDOL is the UDOL to be used for constructing the value field of
 * the COMPUTE CRYPTOGRAPHIC CHECKSUM command if the UDOL in the Card is not present. The
 * Default UDOL must contain as its only entry the tag and length of the Unpredictable Number
 * (Numeric) and has the value: '9F6A04'.
 */
#define TAG_DF811A_DEFAULT_UDOL 0xDF811A

/**
 * Kernel Configuration <p> Indicates the Kernel configuration options.
 */
#define TAG_DF811B_KERNEL_CONFIGURATION 0xDF811B

/**
 * Max Lifetime of Torn Transaction Log Record <p> Maximum time, in seconds, that a record can
 * remain in the Torn Transaction Log.
 */
#define TAG_DF811C_MAX_LIFETIME_OF_TORN_TRANSACTION_LOG_RECORD 0xDF811C

/**
 * Max Number of Torn Transaction Log Records <p> Indicates the maximum number of records that
 * can be stored in the Torn Transaction Log.
 */
#define TAG_DF811D_MAX_NUMBER_OF_TORN_TRANSACTION_LOG_RECORDS 0xDF811D

/**
 * Mag-stripe CVM Capability - CVM Required <p> Indicates the CVM capability of the
 * Terminal/Reader in the case of a mag-stripe mode transaction when the Amount, Authorized
 * (Numeric) is greater than the Reader CVM Required Limit.
 */
#define TAG_DF811E_MAGSTRIPE_CVM_CAPABILITY_CVM_REQUIRED 0xDF811E

/**
 * Security Capability <p> Indicates the security capability of the Kernel. The Security
 * Capability is coded according to Annex A.2 of [EMV Book 4].
 */
#define TAG_DF811F_SECURITY_CAPABILITY 0xDF811F

/**
 * Terminal Action Code - Default <p> Specifies the acquirer's conditions that cause a
 * transaction to be rejected on an offline only Terminal.
 */
#define TAG_DF8120_TERMINAL_ACTION_CODE_DEFAULT 0xDF8120

/**
 * Terminal Action Code - Denial <p> Specifies the acquirer's conditions that cause the denial
 * of a transaction without attempting to go online.
 */
#define TAG_DF8121_TERMINAL_ACTION_CODE_DENIAL 0xDF8121

/**
 * Terminal Action Code - Online <p> Specifies the acquirer's conditions that cause a
 * transaction to be transmitted online on an online capable Terminal.
 */
#define TAG_DF8122_TERMINAL_ACTION_CODE_ONLINE 0xDF8122

/**
 * Reader Contactless Floor Limit <p> Indicates the transaction amount above which transactions
 * must be authorized online.
 */
#define TAG_DF8123_READER_CONTACTLESS_FLOOR_LIMIT 0xDF8123

/**
 * Reader Contactless Transaction Limit (No On-device CVM) <p> Indicates the transaction amount
 * above which the transaction is not allowed, when on device cardholder verification is not
 * supported.
 */
#define TAG_DF8124_READER_CONTACTLESS_TRANSACTION_LIMIT 0xDF8124

/**
 * Reader Contactless Transaction Limit (On-device CVM) <p> Indicates the transaction amount
 * above which the transaction is not allowed, when on device cardholder verification is
 * supported.
 */
#define TAG_DF8125_READER_CONTACTLESS_TRANSACTION_LIMIT 0xDF8125

/**
 * Reader CVM Required Limit <p> Indicates the transaction amount above which the Kernel
 * instantiates the CVM capabilities field in Terminal Capabilities with CVM Capability - CVM
 * Required.
 */
#define TAG_DF8126_READER_CVM_REQUIRED_LIMIT 0xDF8126

/**
 * Time Out Value <p> Defines the time in ms before the timer generates a TIMEOUT signal.
 */
#define TAG_DF8127_TIME_OUT_VALUE 0xDF8127

/**
 * IDS Status <p> Indicates if the transaction performs an IDS read and/or write.
 */
#define TAG_DF8128_IDS_STATUS 0xDF8128

/**
 * Outcome Parameter Set <p> This data object is used to indicate to the Terminal the outcome
 * of the transaction processing by the Kernel. Its value is an accumulation of results about
 * applicable parts of the transaction.
 */
#define TAG_DF8129_OUTCOME_PARAMETER_SET 0xDF8129

/**
 * DD Card (Track1) <p> If Track 1 Data is present, then DD Card (Track1) contains a copy of
 * the discretionary data field of Track 1 Data as returned by the Card in the file read using
 * the READ RECORD command during a mag-stripe mode transaction (i.e. without Unpredictable
 * Number (Numeric), Application Transaction Counter, CVC3 (Track1) and nUN included).
 */
#define TAG_DF812A_DD_CARD 0xDF812A

/**
 * DD Card (Track2) <p> DD Card (Track2) contains a copy of the discretionary data field of
 * Track 2 Data as returned by the Card in the file read using the READ RECORD command during a
 * mag-stripe mode transaction (i.e. without Unpredictable Number (Numeric), Application
 * Transaction Counter, CVC3 (Track2) and nUN included).
 */
#define TAG_DF812B_DD_CARD 0xDF812B

/**
 * Mag-stripe CVM Capability - No CVM Required <p> Indicates the CVM capability of the
 * Terminal/Reader in the case of a mag-stripe mode transaction when the Amount, Authorized
 * (Numeric) is less than or equal to the Reader CVM Required Limit.
 */
#define TAG_DF812C_MAGSTRIPE_CVM_CAPABILITY_NO_CVM_REQUIRED 0xDF812C

/**
 * Message Hold Time <p> Indicates the default delay for the processing of the next MSG signal.
 * The Message Hold Time is an integer in units of 100ms.
 */
#define TAG_DF812D_MESSAGE_HOLD_TIME 0xDF812D

/**
 * Hold Time Value <p> Indicates the time that the field is to be turned off after the
 * transaction is completed if requested to do so by the cardholder device. The Hold Time Value
 * is in units of 100ms.
 */
#define TAG_DF8130_HOLD_TIME_VALUE 0xDF8130

/**
 * Phone Message Table <p> The Phone Message Table is a variable length list of entries of
 * eight bytes each, and defines for the selected AID the message and status identifiers as a
 * function of the POS Cardholder Interaction Information. Each entry in the Phone Message Table
 * contains the fields shown in the table below.Note that the last entry in the Phone Message
 * Table must always have PCII Mask and PCII Value set to '000000'.
 */
#define TAG_DF8131_PHONE_MESSAGE_TABLE 0xDF8131

/**
 * Visa International <p> В
 */
#define TAG_FF60_VISA_INTERNATIONAL 0xFF60

/**
 * Visa Magnetic Stripe <p> В
 */
#define TAG_FF62_VISA_MAGNETIC_STRIPE 0xFF62

/**
 * Visa Quick VSDC <p> В
 */
#define TAG_FF63_VISA_QUICK_VSDC 0xFF63

/**
 * Torn Record <p> A copy of a record from the Torn Transaction Log that is expired. Torn
 * Record is sent to the Terminal as part of the Discretionary Data.
 */
#define TAG_FF8101_TORN_RECORD 0xFF8101

/**
 * Tags To Write Before Gen AC <p> List of data objects indicating the Terminal data writing
 * requests to be sent to the Card before processing the GENERATE AC command or the RECOVER AC
 * command. This data object may be provided several times by the Terminal in a DET signal.
 * Therefore, these values must be accumulated in Tags To Write Yet Before Gen AC buffer.
 */
#define TAG_FF8102_TAGS_TO_WRITE_BEFORE_GEN_AC 0xFF8102

/**
 * Tags To Write After Gen AC <p> Contains the Terminal data writing requests to be sent to the
 * Card after processing the GENERATE AC command or the RECOVER AC command. The value of this
 * data object is composed of a series of TLVs. This data object may be provided several times
 * by the Terminal in a DET signal. Therefore, these values must be accumulated in Tags To Write
 * Yet After Gen AC.
 */
#define TAG_FF8103_TAGS_TO_WRITE_AFTER_GEN_AC 0xFF8103

/**
 * Data To Send <p> List of data objects that contains the accumulated data sent by the Kernel
 * to the Terminal in a DEK signal. These data may correspond to Terminal reading requests,
 * obtained from the Card by means of GET DATA or READ RECORD commands, or may correspond to
 * data that the Kernel posts to the Terminal as part of its own processing.
 */
#define TAG_FF8104_DATA_TO_SEND 0xFF8104

/**
 * Data Record <p> The Data Record is a list of TLV encoded data objects returned with the
 * Outcome Parameter Set on the completion of transaction processing.
 */
#define TAG_FF8105_DATA_RECORD 0xFF8105

/**
 * Discretionary Data <p> The Discretionary Data is a list of Kernel-specific data objects sent
 * to the Terminal as a separate field in the OUT signal.
 */
#define TAG_FF8106_DISCRETIONARY_DATA 0xFF8106

/**
 * Configuration Information
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_E4_CONFIGURATION_INFORMATION 0xE4

/**
 * Configuration Version / Returned Online Tags
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C1_CONFIGURATION_VERSION_RETURNED_ONLINE_TAGS 0xC1

/**
 * Terminal configuration
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_E0_TERMINAL_CONFIGURATION 0xE0

/**
 * Returned tags.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_E5_RETURNED_TAGS 0xE5

/**
 * Returned Complete Tags
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C2_RETURNED_COMPLETE_TAGS 0xC2

/**
 * Application configuration
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_E1_APPLICATION_CONFIGURATION 0xE1

/**
 * Payment engine transaction result
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C1_TRANSACTION_RESULT 0xC1

/**
 * Payment engine cardholder verification method result
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C2_CVM_RESULT 0xC2

/**
 * Payment engine interface.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C3_PAYMENT_INTERFACE 0xC3

/**
 * Payment engine transaction configuration data.
 * <p>
 * 1 BYTE, Configuration data
 * <ul>
 *     <li>BIT1: Show expiration date.</li>
 *     <li>BIT2: Manual entry CVV code.</li>
 * </ul>
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C1_TRANSACTION_CONFIGURATION 0xC1

/**
 * Payment engine: Online result code.
 * <p>
 * This tag specifies whether online transaction is processed successfully or communication
 * error occurs.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C2_ONLINE_RESULT 0xC2

/**
 * Payment engine: Online result data template.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_E6_ONLINE_DATA 0xE6

/**
 * Payment engine: Transaction failure reason.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_C4_TRANSACTION_FAILURE_REASON 0xC4

/**
 * Payment engine: PayPass kernel configuration
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_DF811B_PAYPASS_KERNEL_CONFIGURATION 0xDF811B

/**
 * Payment engine: Visa MSD CVN17 Mode supported.
 * <p>
 * For more information refer to Payment Engine documentation.
 */
#define TAG_DFC309_VISA_MSD_CVN17_SUPPORTED 0xDFC309


#endif //EMVTags_h
