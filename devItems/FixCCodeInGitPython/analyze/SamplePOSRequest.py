import requests
fp='sampleOutput_rate.csv'
# 'Authorize-Token':'b5d8714e74b94adebe4d9cdffbcd3a27'
newHeaders = {'Authorize-Token':'b5d8714e74b94adebe4d9cdffbcd3a27'}
response = requests.post('https://tms.languagetesting.com/LTI.CoreServices/api/dashboard/MachineScorefile',
                         data={
                             'date': '2020-04-04T12:20:06.874Z',
                                'type': '2'
                         },
                         headers=newHeaders)

print("Status code: ", response.status_code)

data = response.content
print("Printing Post JSON data")

fCode=open(fp, 'wb')
fCode.write(data)
fCode.close()

# print(str(responseData))

# print("Content-Type is ", response_Json['headers']['Content-Type'])