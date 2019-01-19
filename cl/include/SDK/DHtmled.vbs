' DHTML Editing Component Constants for VBScript
' Copyright 1998-1999 Microsoft Corporation.  All rights reserved.
'

'
' Command IDs
'
DECMD_BOLD =                      5000
DECMD_COPY =                      5002
DECMD_CUT =                       5003
DECMD_DELETE =                    5004
DECMD_DELETECELLS =               5005
DECMD_DELETECOLS =                5006
DECMD_DELETEROWS =                5007
DECMD_FINDTEXT =                  5008
DECMD_FONT =                      5009
DECMD_GETBACKCOLOR =              5010
DECMD_GETBLOCKFMT =               5011
DECMD_GETBLOCKFMTNAMES =          5012
DECMD_GETFONTNAME =               5013
DECMD_GETFONTSIZE =               5014
DECMD_GETFORECOLOR =              5015
DECMD_HYPERLINK =                 5016
DECMD_IMAGE =                     5017
DECMD_INDENT =                    5018
DECMD_INSERTCELL =                5019
DECMD_INSERTCOL =                 5020
DECMD_INSERTROW =                 5021
DECMD_INSERTTABLE =               5022
DECMD_ITALIC =                    5023
DECMD_JUSTIFYCENTER =             5024
DECMD_JUSTIFYLEFT =               5025
DECMD_JUSTIFYRIGHT =              5026
DECMD_LOCK_ELEMENT =              5027
DECMD_MAKE_ABSOLUTE =             5028
DECMD_MERGECELLS =                5029
DECMD_ORDERLIST =                 5030
DECMD_OUTDENT =                   5031
DECMD_PASTE =                     5032
DECMD_REDO =                      5033
DECMD_REMOVEFORMAT =              5034
DECMD_SELECTALL =                 5035
DECMD_SEND_BACKWARD =             5036
DECMD_BRING_FORWARD =             5037
DECMD_SEND_BELOW_TEXT =           5038
DECMD_BRING_ABOVE_TEXT =          5039
DECMD_SEND_TO_BACK =              5040
DECMD_BRING_TO_FRONT =            5041
DECMD_SETBACKCOLOR =              5042
DECMD_SETBLOCKFMT =               5043
DECMD_SETFONTNAME =               5044
DECMD_SETFONTSIZE =               5045
DECMD_SETFORECOLOR =              5046
DECMD_SPLITCELL =                 5047
DECMD_UNDERLINE =                 5048
DECMD_UNDO =                      5049
DECMD_UNLINK =                    5050
DECMD_UNORDERLIST =               5051
DECMD_PROPERTIES =                5052

'
' Enums
'

' OLECMDEXECOPT  
OLECMDEXECOPT_DODEFAULT =         0 
OLECMDEXECOPT_PROMPTUSER =        1
OLECMDEXECOPT_DONTPROMPTUSER =    2

' DHTMLEDITCMDF
DECMDF_NOTSUPPORTED =             0 
DECMDF_DISABLED =                 1 
DECMDF_ENABLED =                  3
DECMDF_LATCHED =                  7
DECMDF_NINCHED =                  11

' DHTMLEDITAPPEARANCE
DEAPPEARANCE_FLAT =               0
DEAPPEARANCE_3D =                 1 

' OLE_TRISTATE
OLE_TRISTATE_UNCHECKED =          0
OLE_TRISTATE_CHECKED =            1
OLE_TRISTATE_GRAY =               2

'
' Error Return Values
'
DE_E_INVALIDARG =                 &h5
DE_E_ACCESS_DENIED =              &h46
DE_E_PATH_NOT_FOUND =             &h80070003
DE_E_FILE_NOT_FOUND =             &h80070002
DE_E_UNEXPECTED =                 &h8000ffff
DE_E_DISK_FULL =                  &h80070027
DE_E_NOTSUPPORTED =               &h80040100
DE_E_FILTER_FRAMESET =            &h80100001
DE_E_FILTER_SERVERSCRIPT =        &h80100002
DE_E_FILTER_MULTIPLETAGS =        &h80100004
DE_E_FILTER_SCRIPTLISTING =       &h80100008
DE_E_FILTER_SCRIPTLABEL =         &h80100010
DE_E_FILTER_SCRIPTTEXTAREA =      &h80100020
DE_E_FILTER_SCRIPTSELECT =        &h80100040
DE_E_URL_SYNTAX =                 &h800401E4
DE_E_INVALID_URL =                &h800C0002
DE_E_NO_SESSION =                 &h800C0003
DE_E_CANNOT_CONNECT =             &h800C0004
DE_E_RESOURCE_NOT_FOUND =         &h800C0005
DE_E_OBJECT_NOT_FOUND =           &h800C0006
DE_E_DATA_NOT_AVAILABLE =         &h800C0007
DE_E_DOWNLOAD_FAILURE =           &h800C0008
DE_E_AUTHENTICATION_REQUIRED =    &h800C0009
DE_E_NO_VALID_MEDIA =             &h800C000A
DE_E_CONNECTION_TIMEOUT =         &h800C000B
DE_E_INVALID_REQUEST =            &h800C000C
DE_E_UNKNOWN_PROTOCOL =           &h800C000D
DE_E_SECURITY_PROBLEM =           &h800C000E
DE_E_CANNOT_LOAD_DATA =           &h800C000F
DE_E_CANNOT_INSTANTIATE_OBJECT =  &h800C0010
DE_E_REDIRECT_FAILED =            &h800C0014
DE_E_REDIRECT_TO_DIR =            &h800C0015
DE_E_CANNOT_LOCK_REQUEST =        &h800C0016


'' SIG '' Begin signature block
'' SIG '' MIIXPAYJKoZIhvcNAQcCoIIXLTCCFykCAQExCzAJBgUr
'' SIG '' DgMCGgUAMGcGCisGAQQBgjcCAQSgWTBXMDIGCisGAQQB
'' SIG '' gjcCAR4wJAIBAQQQTvApFpkntU2P5azhDxfrqwIBAAIB
'' SIG '' AAIBAAIBAAIBADAhMAkGBSsOAwIaBQAEFEFpEqE5AaWv
'' SIG '' 1ARU9u8oguYWNDTKoIISMTCCBGAwggNMoAMCAQICCi6r
'' SIG '' EdxQ/1ydy8AwCQYFKw4DAh0FADBwMSswKQYDVQQLEyJD
'' SIG '' b3B5cmlnaHQgKGMpIDE5OTcgTWljcm9zb2Z0IENvcnAu
'' SIG '' MR4wHAYDVQQLExVNaWNyb3NvZnQgQ29ycG9yYXRpb24x
'' SIG '' ITAfBgNVBAMTGE1pY3Jvc29mdCBSb290IEF1dGhvcml0
'' SIG '' eTAeFw0wNzA4MjIyMjMxMDJaFw0xMjA4MjUwNzAwMDBa
'' SIG '' MHkxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNoaW5n
'' SIG '' dG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQKExVN
'' SIG '' aWNyb3NvZnQgQ29ycG9yYXRpb24xIzAhBgNVBAMTGk1p
'' SIG '' Y3Jvc29mdCBDb2RlIFNpZ25pbmcgUENBMIIBIjANBgkq
'' SIG '' hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAt3l91l2zRTmo
'' SIG '' NKwx2vklNUl3wPsfnsdFce/RRujUjMNrTFJi9JkCw03Y
'' SIG '' SWwvJD5lv84jtwtIt3913UW9qo8OUMUlK/Kg5w0jH9FB
'' SIG '' JPpimc8ZRaWTSh+ZzbMvIsNKLXxv2RUeO4w5EDndvSn0
'' SIG '' ZjstATL//idIprVsAYec+7qyY3+C+VyggYSFjrDyuJSj
'' SIG '' zzimUIUXJ4dO3TD2AD30xvk9gb6G7Ww5py409rQurwp9
'' SIG '' YpF4ZpyYcw2Gr/LE8yC5TxKNY8ss2TJFGe67SpY7UFMY
'' SIG '' zmZReaqth8hWPp+CUIhuBbE1wXskvVJmPZlOzCt+M26E
'' SIG '' RwbRntBKhgJuhgCkwIffUwIDAQABo4H6MIH3MBMGA1Ud
'' SIG '' JQQMMAoGCCsGAQUFBwMDMIGiBgNVHQEEgZowgZeAEFvQ
'' SIG '' cO9pcp4jUX4Usk2O/8uhcjBwMSswKQYDVQQLEyJDb3B5
'' SIG '' cmlnaHQgKGMpIDE5OTcgTWljcm9zb2Z0IENvcnAuMR4w
'' SIG '' HAYDVQQLExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xITAf
'' SIG '' BgNVBAMTGE1pY3Jvc29mdCBSb290IEF1dGhvcml0eYIP
'' SIG '' AMEAizw8iBHRPvZj7N9AMA8GA1UdEwEB/wQFMAMBAf8w
'' SIG '' HQYDVR0OBBYEFMwdznYAcFuv8drETppRRC6jRGPwMAsG
'' SIG '' A1UdDwQEAwIBhjAJBgUrDgMCHQUAA4IBAQB7q65+Siby
'' SIG '' zrxOdKJYJ3QqdbOG/atMlHgATenK6xjcacUOonzzAkPG
'' SIG '' yofM+FPMwp+9Vm/wY0SpRADulsia1Ry4C58ZDZTX2h6t
'' SIG '' KX3v7aZzrI/eOY49mGq8OG3SiK8j/d/p1mkJkYi9/uEA
'' SIG '' uzTz93z5EBIuBesplpNCayhxtziP4AcNyV1ozb2AQWtm
'' SIG '' qLu3u440yvIDEHx69dLgQt97/uHhrP7239UNs3DWkuNP
'' SIG '' tjiifC3UPds0C2I3Ap+BaiOJ9lxjj7BauznXYIxVhBoz
'' SIG '' 9TuYoIIMol+Lsyy3oaXLq9ogtr8wGYUgFA0qvFL0QeBe
'' SIG '' MOOSKGmHwXDi86erzoBCcnYOMIIEejCCA2KgAwIBAgIK
'' SIG '' YQHPPgAAAAAADzANBgkqhkiG9w0BAQUFADB5MQswCQYD
'' SIG '' VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
'' SIG '' A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
'' SIG '' IENvcnBvcmF0aW9uMSMwIQYDVQQDExpNaWNyb3NvZnQg
'' SIG '' Q29kZSBTaWduaW5nIFBDQTAeFw0wOTEyMDcyMjQwMjla
'' SIG '' Fw0xMTAzMDcyMjQwMjlaMIGDMQswCQYDVQQGEwJVUzET
'' SIG '' MBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVk
'' SIG '' bW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0
'' SIG '' aW9uMQ0wCwYDVQQLEwRNT1BSMR4wHAYDVQQDExVNaWNy
'' SIG '' b3NvZnQgQ29ycG9yYXRpb24wggEiMA0GCSqGSIb3DQEB
'' SIG '' AQUAA4IBDwAwggEKAoIBAQC9MIn7RXKoU2ueiU8AI8C+
'' SIG '' 1B09sVlAOPNzkYIm5pYSAFPZHIIOPM4du733Qo2X1Pw4
'' SIG '' GuS5+ePs02EDv6DT1nVNXEap7V7w0uJpWxpz6rMcjQTN
'' SIG '' KUSgZFkvHphdbserGDmCZcSnvKt1iBnqh5cUJrN/Jnak
'' SIG '' 1Dg5hOOzJtUY+Svp0skWWlQh8peNh4Yp/vRJLOaL+AQ/
'' SIG '' fc3NlpKGDXED4tD+DEI1/9e4P92ORQp99tdLrVvwdnId
'' SIG '' dyN9iTXEHF2yUANLR20Hp1WImAaApoGtVE7Ygdb6v0LA
'' SIG '' Mb5VDZnVU0kSMOvlpYh8XsR6WhSHCLQ3aaDrMiSMCOv5
'' SIG '' 1BS64PzN6qQVAgMBAAGjgfgwgfUwEwYDVR0lBAwwCgYI
'' SIG '' KwYBBQUHAwMwHQYDVR0OBBYEFDh4BXPIGzKbX5KGVa+J
'' SIG '' usaZsXSOMA4GA1UdDwEB/wQEAwIHgDAfBgNVHSMEGDAW
'' SIG '' gBTMHc52AHBbr/HaxE6aUUQuo0Rj8DBEBgNVHR8EPTA7
'' SIG '' MDmgN6A1hjNodHRwOi8vY3JsLm1pY3Jvc29mdC5jb20v
'' SIG '' cGtpL2NybC9wcm9kdWN0cy9DU1BDQS5jcmwwSAYIKwYB
'' SIG '' BQUHAQEEPDA6MDgGCCsGAQUFBzAChixodHRwOi8vd3d3
'' SIG '' Lm1pY3Jvc29mdC5jb20vcGtpL2NlcnRzL0NTUENBLmNy
'' SIG '' dDANBgkqhkiG9w0BAQUFAAOCAQEAKAODqxMN8f4Rb0J2
'' SIG '' 2EOruMZC+iRlNK51sHEwjpa2g/py5P7NN+c6cJhRIA66
'' SIG '' cbTJ9NXkiugocHPV7eHCe+7xVjRagILrENdyA+oSTuzd
'' SIG '' DYx7RE8MYXX9bpwH3c4rWhgNObBg/dr/BKoCo9j6jqO7
'' SIG '' vcFqVDsxX+QsbsvxTSoc8h52e4avxofWsSrtrMwOwOSf
'' SIG '' f+jP6IRyVIIYbirInpW0Gh7Bb5PbYqbBS2utye09kuOy
'' SIG '' L6t6dzlnagB7gp0DEN5jlUkmQt6VIsGHC9AUo1/cczJy
'' SIG '' Nh7/yCnFJFJPZkjJHR2pxSY5aVBOp+zCBmwuchvxIdpt
'' SIG '' JEiAgRVAfJ/MdDhKTzCCBJ0wggOFoAMCAQICEGoLmU/A
'' SIG '' ACWrEdtFH1h6Z6IwDQYJKoZIhvcNAQEFBQAwcDErMCkG
'' SIG '' A1UECxMiQ29weXJpZ2h0IChjKSAxOTk3IE1pY3Jvc29m
'' SIG '' dCBDb3JwLjEeMBwGA1UECxMVTWljcm9zb2Z0IENvcnBv
'' SIG '' cmF0aW9uMSEwHwYDVQQDExhNaWNyb3NvZnQgUm9vdCBB
'' SIG '' dXRob3JpdHkwHhcNMDYwOTE2MDEwNDQ3WhcNMTkwOTE1
'' SIG '' MDcwMDAwWjB5MQswCQYDVQQGEwJVUzETMBEGA1UECBMK
'' SIG '' V2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwG
'' SIG '' A1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9uMSMwIQYD
'' SIG '' VQQDExpNaWNyb3NvZnQgVGltZXN0YW1waW5nIFBDQTCC
'' SIG '' ASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANw3
'' SIG '' bvuvyEJKcRjIzkg+U8D6qxS6LDK7Ek9SyIPtPjPZSTGS
'' SIG '' KLaRZOAfUIS6wkvRfwX473W+i8eo1a5pcGZ4J2botrfv
'' SIG '' hbnN7qr9EqQLWSIpL89A2VYEG3a1bWRtSlTb3fHev5+D
'' SIG '' x4Dff0wCN5T1wJ4IVh5oR83ZwHZcL322JQS0VltqHGP/
'' SIG '' gHw87tUEJU05d3QHXcJc2IY3LHXJDuoeOQl8dv6dbG56
'' SIG '' 4Ow+j5eecQ5fKk8YYmAyntKDTisiXGhFi94vhBBQsvm1
'' SIG '' Go1s7iWbE/jLENeFDvSCdnM2xpV6osxgBuwFsIYzt/iU
'' SIG '' W4RBhFiFlG6wHyxIzG+cQ+Bq6H8mjmsCAwEAAaOCASgw
'' SIG '' ggEkMBMGA1UdJQQMMAoGCCsGAQUFBwMIMIGiBgNVHQEE
'' SIG '' gZowgZeAEFvQcO9pcp4jUX4Usk2O/8uhcjBwMSswKQYD
'' SIG '' VQQLEyJDb3B5cmlnaHQgKGMpIDE5OTcgTWljcm9zb2Z0
'' SIG '' IENvcnAuMR4wHAYDVQQLExVNaWNyb3NvZnQgQ29ycG9y
'' SIG '' YXRpb24xITAfBgNVBAMTGE1pY3Jvc29mdCBSb290IEF1
'' SIG '' dGhvcml0eYIPAMEAizw8iBHRPvZj7N9AMBAGCSsGAQQB
'' SIG '' gjcVAQQDAgEAMB0GA1UdDgQWBBRv6E4/l7k0q0uGj7yc
'' SIG '' 6qw7QUPG0DAZBgkrBgEEAYI3FAIEDB4KAFMAdQBiAEMA
'' SIG '' QTALBgNVHQ8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAN
'' SIG '' BgkqhkiG9w0BAQUFAAOCAQEAlE0RMcJ8ULsRjqFhBwEO
'' SIG '' jHBFje9zVL0/CQUt/7hRU4Uc7TmRt6NWC96Mtjsb0fus
'' SIG '' p8m3sVEhG28IaX5rA6IiRu1stG18IrhG04TzjQ++B4o2
'' SIG '' wet+6XBdRZ+S0szO3Y7A4b8qzXzsya4y1Ye5y2PENtEY
'' SIG '' Ib923juasxtzniGI2LS0ElSM9JzCZUqaKCacYIoPO8cT
'' SIG '' ZXhIu8+tgzpPsGJY3jDp6Tkd44ny2jmB+RMhjGSAYwYE
'' SIG '' lvKaAkMve0aIuv8C2WX5St7aA3STswVuDMyd3ChhfEjx
'' SIG '' F5wRITgCHIesBsWWMrjlQMZTPb2pid7oZjeN9CKWnMyw
'' SIG '' d1RROtZyRLIj9jCCBKowggOSoAMCAQICCmEGlC0AAAAA
'' SIG '' AAkwDQYJKoZIhvcNAQEFBQAweTELMAkGA1UEBhMCVVMx
'' SIG '' EzARBgNVBAgTCldhc2hpbmd0b24xEDAOBgNVBAcTB1Jl
'' SIG '' ZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3Jh
'' SIG '' dGlvbjEjMCEGA1UEAxMaTWljcm9zb2Z0IFRpbWVzdGFt
'' SIG '' cGluZyBQQ0EwHhcNMDgwNzI1MTkwMjE3WhcNMTMwNzI1
'' SIG '' MTkxMjE3WjCBszELMAkGA1UEBhMCVVMxEzARBgNVBAgT
'' SIG '' Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
'' SIG '' BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjENMAsG
'' SIG '' A1UECxMETU9QUjEnMCUGA1UECxMebkNpcGhlciBEU0Ug
'' SIG '' RVNOOjdBODItNjg4QS05RjkyMSUwIwYDVQQDExxNaWNy
'' SIG '' b3NvZnQgVGltZS1TdGFtcCBTZXJ2aWNlMIIBIjANBgkq
'' SIG '' hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAlYEKIEIYUXrZ
'' SIG '' le2b/dyH0fsOjxPqqjcoEnb+TVCrdpcqk0fgqVZpAuWU
'' SIG '' fk2F239x73UA27tDbPtvrHHwK9F8ks6UF52hxbr5937d
'' SIG '' YeEtMB6cJi12P+ZGlo6u2Ik32Mzv889bw/xo4PJkj5vo
'' SIG '' wxL5o76E/NaLzgU9vQF2UCcD+IS3FoaNYL5dKSw8z6X9
'' SIG '' mFo1HU8WwDjYHmE/PTazVhQVd5U7EPoAsJPiXTerJ7tj
'' SIG '' LEgUgVXjbOqpK5WNiA5+owCldyQHmCpwA7gqJJCa3sWi
'' SIG '' Iku/TFkGd1RyQ7A+ZN2ThAhYtv7ph0kJNrOz+DOpfkyi
'' SIG '' eX8yWSkOnrX14DyeP+xGOwIDAQABo4H4MIH1MB0GA1Ud
'' SIG '' DgQWBBQolYi/Ajvr2pS6fUYP+sv0fp3/0TAfBgNVHSME
'' SIG '' GDAWgBRv6E4/l7k0q0uGj7yc6qw7QUPG0DBEBgNVHR8E
'' SIG '' PTA7MDmgN6A1hjNodHRwOi8vY3JsLm1pY3Jvc29mdC5j
'' SIG '' b20vcGtpL2NybC9wcm9kdWN0cy90c3BjYS5jcmwwSAYI
'' SIG '' KwYBBQUHAQEEPDA6MDgGCCsGAQUFBzAChixodHRwOi8v
'' SIG '' d3d3Lm1pY3Jvc29mdC5jb20vcGtpL2NlcnRzL3RzcGNh
'' SIG '' LmNydDATBgNVHSUEDDAKBggrBgEFBQcDCDAOBgNVHQ8B
'' SIG '' Af8EBAMCBsAwDQYJKoZIhvcNAQEFBQADggEBAADurPzi
'' SIG '' 0ohmyinjWrnNAIJ+F1zFJFkSu6j3a9eH/o3LtXYfGyL2
'' SIG '' 9+HKtLlBARo3rUg3lnD6zDOnKIy4C7Z0Eyi3s3XhKgni
'' SIG '' i0/fmD+XtzQSgeoQ3R3cumTPTlA7TIr9Gd0lrtWWh+pL
'' SIG '' xOXw+UEXXQHrV4h9dnrlb/6HIKyTnIyav18aoBUwJOCi
'' SIG '' fmGRHSkpw0mQOkODie7e1YPdTyw1O+dBQQGqAAwL8tZJ
'' SIG '' G85CjXuw8y2NXSnhvo1/kRV2tGD7FCeqbxJjQihYOoo7
'' SIG '' i0Dkt8XMklccRlZrj8uSTVYFAMr4MEBFTt8ZiL31EPDd
'' SIG '' Gt8oHrRR8nfgJuO7CYES3B460EUxggR3MIIEcwIBATCB
'' SIG '' hzB5MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
'' SIG '' Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
'' SIG '' TWljcm9zb2Z0IENvcnBvcmF0aW9uMSMwIQYDVQQDExpN
'' SIG '' aWNyb3NvZnQgQ29kZSBTaWduaW5nIFBDQQIKYQHPPgAA
'' SIG '' AAAADzAJBgUrDgMCGgUAoIGiMBkGCSqGSIb3DQEJAzEM
'' SIG '' BgorBgEEAYI3AgEEMBwGCisGAQQBgjcCAQsxDjAMBgor
'' SIG '' BgEEAYI3AgEVMCMGCSqGSIb3DQEJBDEWBBQYBjSN2uvt
'' SIG '' LGL/HdcSZnm7qd/7FTBCBgorBgEEAYI3AgEMMTQwMqAY
'' SIG '' gBYARABIAHQAbQBsAGUAZAAuAHYAYgBzoRaAFGh0dHA6
'' SIG '' Ly9taWNyb3NvZnQuY29tMA0GCSqGSIb3DQEBAQUABIIB
'' SIG '' ALRxMhB6BgU/1zQYJj/qHDfUo0UvJOHFxEVP4tTEfIth
'' SIG '' RJK7OYIgrCVPte1j/vvBBmig/VaBcLfmTEBiArtSbJmo
'' SIG '' 6e7jeLlY6l6U2gbeBBiJISeIOY8NnMarBkAEVBaQqXGq
'' SIG '' Uf/Sh8yWRpQg3m4tB8x2YcxNMmYBqf+e7pTpyZPisoJk
'' SIG '' 8AkBwaMk82e+TsQYbrGlaeTyovhnmpxkcULNkL9yhgCv
'' SIG '' J1PrtJWUnRg99vBH0IFCO7OeUEl3OhFp3rHhasTtmv3X
'' SIG '' Ly5Dgp+I2AuLGSj+fG/NyimrfgBf6Q/IV+Y52URuiqNW
'' SIG '' F/GzCbSQg8NAg1AZ/S9N6Zz4CG52w+ujBiWhggIfMIIC
'' SIG '' GwYJKoZIhvcNAQkGMYICDDCCAggCAQEwgYcweTELMAkG
'' SIG '' A1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0b24xEDAO
'' SIG '' BgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29m
'' SIG '' dCBDb3Jwb3JhdGlvbjEjMCEGA1UEAxMaTWljcm9zb2Z0
'' SIG '' IFRpbWVzdGFtcGluZyBQQ0ECCmEGlC0AAAAAAAkwBwYF
'' SIG '' Kw4DAhqgXTAYBgkqhkiG9w0BCQMxCwYJKoZIhvcNAQcB
'' SIG '' MBwGCSqGSIb3DQEJBTEPFw0xMDA1MDQxNDExMDhaMCMG
'' SIG '' CSqGSIb3DQEJBDEWBBS52NlgfF58W+46Olf2fAmulTYi
'' SIG '' +DANBgkqhkiG9w0BAQUFAASCAQABiTsYS2XM86U2qN9p
'' SIG '' gGukdvdn8Nz99HpyTeejzWQpijA6gt2UMN+sN+nWMACj
'' SIG '' Vr+pfFwcphKAZ0O2lRUUV503iuNdaRp2pUncFWtdYwe+
'' SIG '' rJnaZS1NVJ6D/k6LrH71PiArGpUXyLwresD0f/5DHiE2
'' SIG '' 2T16khxDYDvnHwVEplhwi5fHMIPBoDeaMpJbCkAkkWOM
'' SIG '' Hr77suBY7eSlUZiI+IArrFV7tKzAfoTThSXzwGQ+7XE6
'' SIG '' zCUsvYemqVWyt1P/hdN9s2+VrMO8yJbhWf+NgdEiySMl
'' SIG '' 4xLxyIXBaXUo2m1FM/5Ines6pne9nP2oKmdh073LyBqD
'' SIG '' OXvakLUqrQ1u7Q6M
'' SIG '' End signature block
