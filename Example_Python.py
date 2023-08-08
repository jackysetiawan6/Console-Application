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


# import cv2
# cascPath = "Datasets/haarcascade_frontalface_default.xml"
# faceCascade = cv2.CascadeClassifier(cascPath)
# video_capture = cv2.VideoCapture(0)
# while True:
#     video_capture.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
#     ret, frame = video_capture.read()
#     gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#     faces = faceCascade.detectMultiScale(
#         gray,
#         scaleFactor=2,
#         minNeighbors=5,
#         minSize=(30, 30),
#         flags=cv2.CASCADE_SCALE_IMAGE
#     )
#     for (x, y, w, h) in faces:
#         cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
#     cv2.imshow('Video', frame)
#     if cv2.waitKey(1) & 0xFF == ord('q'):
#         break
# video_capture.release()
# cv2.destroyAllWindows()


# import numpy as np
# import cv2
# from collections import deque
# import mediapipe as mp
# from mediapipe.python.solutions.drawing_utils import _normalized_to_pixel_coordinates
# mp_drawing = mp.solutions.drawing_utils # type: ignore
# mp_hands = mp.solutions.hands # type: ignore
# def get_idx_to_coordinates(image, results, VISIBILITY_THRESHOLD=0.5, PRESENCE_THRESHOLD=0.5):
#     idx_to_coordinates = {}
#     image_rows, image_cols, _ = image.shape
#     try:
#         for idx, landmark in enumerate(results.multi_hand_landmarks[0].landmark):
#             if ((landmark.HasField('visibility') and
#                  landmark.visibility < VISIBILITY_THRESHOLD) or
#                     (landmark.HasField('presence') and
#                      landmark.presence < PRESENCE_THRESHOLD)):
#                 continue
#             landmark_px = _normalized_to_pixel_coordinates(landmark.x, landmark.y,
#                                                            image_cols, image_rows)
#             if landmark_px:
#                 idx_to_coordinates[idx] = landmark_px
#     except:
#         pass
#     return idx_to_coordinates
# def rescale_frame(frame, percent=75):
#     width = int(frame.shape[1] * percent / 100)
#     height = int(frame.shape[0] * percent / 100)
#     dim = (width, height)
#     return cv2.resize(frame, dim, interpolation=cv2.INTER_AREA)
# def main():
#     hands = mp_hands.Hands(
#         min_detection_confidence=0.7, min_tracking_confidence=0.7)
#     hand_landmark_drawing_spec = mp_drawing.DrawingSpec(thickness=5, circle_radius=5)
#     hand_connection_drawing_spec = mp_drawing.DrawingSpec(thickness=10, circle_radius=10)
#     cap = cv2.VideoCapture(0)
#     pts = deque(maxlen=64)
#     while cap.isOpened():
#         idx_to_coordinates = {}
#         ret, image = cap.read()
#         image = cv2.flip(image, 1)
#         image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
#         results_hand = hands.process(image)
#         image.flags.writeable = True
#         image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
#         if results_hand.multi_hand_landmarks:
#             for hand_landmarks in results_hand.multi_hand_landmarks:
#                 mp_drawing.draw_landmarks(
#                     image=image,
#                     landmark_list=hand_landmarks,
#                     connections=mp_hands.HAND_CONNECTIONS,
#                     landmark_drawing_spec=hand_landmark_drawing_spec,
#                     connection_drawing_spec=hand_connection_drawing_spec)
#                 idx_to_coordinates = get_idx_to_coordinates(image, results_hand)
#         if 8 in idx_to_coordinates:
#             pts.appendleft(idx_to_coordinates[8])
#         for i in range(1, len(pts)):
#             if pts[i - 1] is None or pts[i] is None:
#                 continue
#             thick = int(np.sqrt(len(pts) / float(i + 1)) * 4.5)
#             cv2.line(image, pts[i - 1], pts[i], (0, 255, 0), thick)
#         cv2.imshow("Res", rescale_frame(image, percent=130))
#         if cv2.waitKey(5) & 0xFF == 27:
#             break
#     hands.close()
#     cap.release()
# if __name__ == '__main__':
#     main()
