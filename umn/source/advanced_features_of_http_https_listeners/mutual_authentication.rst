:original_name: en_us_elb_03_0006.html

.. _en_us_elb_03_0006:

Mutual Authentication
=====================

Scenarios
---------

In common HTTPS service scenarios, only the server certificate is required for authentication. For some mission-critical services, such as financial transactions, you need to deploy both the server certificate and the client certificate for mutual authentication.

This section uses self-signed certificates as an example to describe how to configure mutual authentication. Self-signed certificates do not provide all the security properties provided by certificates signed by a CA. It is recommended that you purchase certificates from other CAs.

.. _en_us_elb_03_0006__section1271620810310:

Creating a CA Certificate Using OpenSSL
---------------------------------------

#. Log in to a Linux server with OpenSSL installed.

#. Create the **server** directory and switch to the directory:

   **mkdir ca**

   **cd ca**

#. Create the certificate configuration file **ca_cert.conf**. The file content is as follows:

   .. code-block::

      [ req ]
      distinguished_name     = req_distinguished_name
      prompt                 = no

      [ req_distinguished_name ]
       O                      = ELB

#. Create the CA certificate private key **ca.key**.

   **openssl genrsa -out ca.key 2048**


   .. figure:: /_static/images/en-us_image_0000001747381096.jpg
      :alt: **Figure 1** Private key of the CA certificate

      **Figure 1** Private key of the CA certificate

#. Create the certificate signing request (CSR) file **ca.csr** for the CA certificate.

   **openssl req -out ca.csr -key ca.key -new -config ./ca_cert.conf**

#. Create the self-signed CA certificate **ca.crt**.

   **openssl x509 -req -in ca.csr -out ca.crt -sha1 -days 5000 -signkey ca.key**


   .. figure:: /_static/images/en-us_image_0000001747739988.jpg
      :alt: **Figure 2** Creating a self-signed CA certificate

      **Figure 2** Creating a self-signed CA certificate

Issuing a Server Certificate Using the CA Certificate
-----------------------------------------------------

The server certificate can be a CA signed certificate or a self-signed one. In the following steps, a self-signed certificate is used as an example to describe how to create a server certificate.

#. Log in to the server where the CA certificate is generated.

#. Create a directory at the same level as the directory of the CA certificate and switch to the directory.

   **mkdir server**

   **cd server**

#. Create the certificate configuration file **server_cert.conf**. The file content is as follows:

   .. code-block::

      [ req ]
      distinguished_name     = req_distinguished_name
      prompt                 = no

      [ req_distinguished_name ]
       O                      = ELB
       CN                     = www.test.com

   .. note::

      Set the **CN** field to the domain name or IP address of the Linux server.

#. Create the server certificate private key **server.key**.

   **openssl genrsa -out server.key 2048**

#. Create the CSR file **server.csr** for the server certificate.

   **openssl req -out server.csr -key server.key -new -config ./server_cert.conf**

#. Use the CA certificate to issue the server certificate **server.crt**.

   **openssl x509 -req -in server.csr -out server.crt -sha1 -CAcreateserial -days 5000** **-CA ../ca/ca.crt -CAkey ../ca/ca.key**


   .. figure:: /_static/images/en-us_image_0000001794660833.jpg
      :alt: **Figure 3** Issuing a server certificate

      **Figure 3** Issuing a server certificate

Issuing a Client Certificate Using the CA Certificate
-----------------------------------------------------

#. Log in to the server where the CA certificate is generated.

#. Create a directory at the same level as the directory of the CA certificate and switch to the directory.

   **mkdir client**

   **cd client**

#. Create the certificate configuration file **client_cert.conf**. The file content is as follows:

   .. code-block::

      [ req ]
      distinguished_name     = req_distinguished_name
      prompt                 = no

      [ req_distinguished_name ]
       O                      = ELB
       CN                     = www.test.com

   .. note::

      Set the **CN** field to the domain name or IP address of the Linux server.

#. Create the client certificate private key **client.key**.

   **openssl genrsa -out client.key 2048**


   .. figure:: /_static/images/en-us_image_0000001747739980.jpg
      :alt: **Figure 4** Creating a client certificate private key

      **Figure 4** Creating a client certificate private key

#. Create the CSR file **client.csr** for the client certificate.

   **openssl req -out client.csr -key client.key -new -config ./client_cert.conf**


   .. figure:: /_static/images/en-us_image_0000001747739976.jpg
      :alt: **Figure 5** Creating a client certificate CSR file

      **Figure 5** Creating a client certificate CSR file

#. Use the CA certificate to issue the client certificate **client.crt**.

   **openssl x509 -req -in client.csr -out client.crt -sha1 -CAcreateserial -days 5000** **-CA ../ca/ca.crt -CAkey ../ca/ca.key**


   .. figure:: /_static/images/en-us_image_0000001747739964.jpg
      :alt: **Figure 6** Issuing a client certificate

      **Figure 6** Issuing a client certificate

#. Convert the client certificate to a **.p12** file that can be identified by the browser.

   **openssl pkcs12 -export -clcerts -in client.crt -inkey client.key -out client.p12**

   .. note::

      A password is required during command execution. Save this password, which will be required when you import the certificate using the browser.

Configuring the Server Certificate and Private Key
--------------------------------------------------

#. Log in to the load balancer management console.
#. In the navigation pane on the left, choose **Certificates**.
#. In the navigation pane on the left, choose **Certificates**. On the displayed page, click **Create Certificate**. In the **Create Certificate** dialog box, select **Server certificate**, copy the content of server certificate **server.crt** to the **Certificate Content** area and the content of private key file **server.key** to the **Private Key** area, and click **OK**.

   .. note::

      Delete the last newline character before you copy the content.

   .. note::

      The certificate and private key must be PEM-encoded.

Configuring the CA Certificate
------------------------------

#. Log in to the load balancer management console.

#. In the navigation pane on the left, choose **Certificates**.

#. Click **Create Certificate**. In the **Create Certificate** dialog box, select **CA certificate**, copy the content of CA certificate **ca.crt** created in :ref:`Creating a CA Certificate Using OpenSSL <en_us_elb_03_0006__section1271620810310>` to the **Certificate Content** area, and click **OK**.

   .. note::

      Delete the last newline character before you copy the content.


   .. figure:: /_static/images/en-us_image_0000001747739968.png
      :alt: **Figure 7** Creating a certificate

      **Figure 7** Creating a certificate

   .. note::

      The certificate must be PEM-encoded.

Configuring Mutual Authentication
---------------------------------

#. Log in to the load balancer management console.

#. Locate the load balancer and click its name. Under **Listeners**, click **Add Listener**. Select **HTTPS** for **Frontend Protocol**, enable **Mutual Authentication**, and select the CA certificate and server certificate.


   .. figure:: /_static/images/en-us_image_0000001747739972.png
      :alt: **Figure 8** Adding a listener

      **Figure 8** Adding a listener

**Add backend servers**.

For detailed operations, see :ref:`Overview <elb_ug_hd3_0001>`.

Importing and Testing the Client Certificate
--------------------------------------------

**Method 1: Using a browser**

#. Import the client certificate using a browser (Internet Explorer 11 is used as an example).

   a. Export **client.p12** from the Linux server.

   b. Open the browser, choose **Settings** > **Internet Options** and click **Content**.

   c. Click **Certificates** and then **Import** to import the **client.p12** certificate.


      .. figure:: /_static/images/en-us_image_0000001794660809.png
         :alt: **Figure 9** Importing the **client.p12** certificate

         **Figure 9** Importing the **client.p12** certificate

#. Verify the import.

   Enter the access address in the address box of your browser. A window is displayed asking you to select the certificate. Select the client certificate and click **OK**. If the website can be accessed, the certificate is successfully imported.


   .. figure:: /_static/images/en-us_image_0000001747381076.png
      :alt: **Figure 10** Accessing the website

      **Figure 10** Accessing the website

**Method 2: Using cURL**

#. Import the client certificate.

   Copy client certificate **client.crt** and private key **client.key** to a new directory, for example, **/home/client_cert**.

#. Verify the import.

   On the Shell screen, run the following command:

   .. code-block::

      curl -k --cert /home/client_cert/client.crt --key /home/client_cert/client.key https://XXX.XXX.XXX.XXX:XXX/ -I

   Ensure that the certificate address, private key address, IP address and listening port of the load balancer are correct. Replace **https://XXX.XXX.XXX.XXX:XXX** with the actual IP address and port number. If the expected response code is returned, the certificate is successfully imported.


   .. figure:: /_static/images/en-us_image_0000001794660817.png
      :alt: **Figure 11** Example of a correct response code

      **Figure 11** Example of a correct response code
