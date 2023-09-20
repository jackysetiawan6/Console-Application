# import math
# import turtle
# turtle.title("To Regina")
# turtle.shape("turtle")
# turtle.setup(width=900, height=700)
# turtle.speed(0)
# turtle.bgcolor('black')
# turtle.color('red')
# def heart1(h):
#     return 15 * math.sin(h) ** 3
# def heart2(h):
#     return 12 * math.cos(h) - 5 * math.cos(2 * h) - 2 * math.cos(3 * h) - math.cos(4 * h)
# for i in range(600):
#     x, y = heart1(i) * 20, heart2(i) * 20
#     turtle.goto(x, y)
# turtle.penup()
# turtle.goto(0, -45)
# turtle.pendown()
# turtle.write('I Love You', align='center', font=('Arial', 50, 'bold'))
# turtle.done()


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