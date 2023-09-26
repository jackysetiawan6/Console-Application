#region Get Location Details based on IP Address

# import requests
# def get_ip():
#     response = requests.get('http://api64.ipify.org?format=json').json()
#     return response['ip']
# def get_location(ip_address):
#     response = requests.get(f'http://ipapi.co/{ip_address}/json/').json()
#     location_data = {
#         'ip': response.get('ip'),
#         'country': response.get('country'),
#         'region': response.get('region'),
#         'city': response.get('city'),
#         'postal_code': response.get('postal_code'),
#         'latitude': response.get('latitude'),
#         'longitude': response.get('longitude'),
#         'timezone': response.get('timezone'),
#         'utc_offset': response.get('utc_offset'),
#         'country_calling_code': response.get('country_calling_code'),
#         'currency': response.get('currency'),
#         'languages': response.get('languages'),
#         'asn': response.get('asn'),
#         'org': response.get('org')
#     }
#     return location_data
# for key, value in get_location(get_ip()).items():
#     print(f'{key:20}: {value}')

#endregion

#region Beelingua Automation

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

base_address = 'https://newbinusmaya.binus.ac.id/beelingua/'
current_address = 'https://newbinusmaya.binus.ac.id/beelingua/student/class/ec84d186-38f0-416c-b522-2efc0149686a/session/f7aced90-5950-4c56-b468-ce54923660d9/content/939544d4-f6f1-4192-9863-7bbe8cd1a98b/BlExercise/06561ba6-a050-495d-bb37-2d10ad57d947'

def get_driver():
    service = Service(ChromeDriverManager().install())
    driver = webdriver.Chrome(service=service)
    return driver

browser = get_driver()
browser.get(current_address)

# get text from element <p> with class ' '
element = browser.find_element_by_class_name(' ')
print(element.text)

browser.quit()

#endregion