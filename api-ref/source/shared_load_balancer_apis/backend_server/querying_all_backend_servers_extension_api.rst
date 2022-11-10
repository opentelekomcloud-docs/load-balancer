:original_name: elb_zq_hd_0006.html

.. _elb_zq_hd_0006:

Querying All Backend Servers (Extension API)
============================================

Function
--------

This API is used to query all backend servers. Filter query and pagination query are supported.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v2.0/lbaas/members

Request
-------

.. table:: **Table 1** Parameter description

   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                |
   +==================+=================+=================+============================================================================================================================================================================================================================================================================================================================================+
   | marker           | No              | String          | Specifies the ID of the backend server from which pagination query starts, that is, the ID of the last backend server on the previous page. If this parameter is not specified, the first page will be queried.                                                                                                                            |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit            | No              | Integer         | Specifies the number of backend servers on each page. If this parameter is not set, all backend servers are queried by default.                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse     | No              | Boolean         | Specifies the page direction. The value can be **true** or **false**, and the default value is **false**. The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id               | No              | String          | Specifies the backend server ID.                                                                                                                                                                                                                                                                                                           |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | .. note::                                                                                                                                                                                                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 |    The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer.                                                                                                                                                                    |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name             | No              | String          | Specifies the backend server name.                                                                                                                                                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address          | No              | String          | Specifies the private IP address of the backend server.                                                                                                                                                                                                                                                                                    |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value contains a maximum of 64 characters.                                                                                                                                                                                                                                                                                             |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port    | No              | Integer         | Specifies the port used by the backend server.                                                                                                                                                                                                                                                                                             |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id        | No              | String          | Specifies the ID of the subnet where the backend server works.                                                                                                                                                                                                                                                                             |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up   | No              | Boolean         | Specifies the administrative status of the backend server.                                                                                                                                                                                                                                                                                 |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                                                                                                                                                                             |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight           | No              | Integer         | Specifies the backend server weight.                                                                                                                                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id  | No              | String          | Specifies the backend server ID.                                                                                                                                                                                                                                                                                                           |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status | No              | String          | Specifies the health check result of the backend server. The value can be one of the following:                                                                                                                                                                                                                                            |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                                                                                                     |
   |                  |                 |                 | -  **NO_MONITOR**: No health check is performed on the backend server.                                                                                                                                                                                                                                                                     |
   |                  |                 |                 | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The default value is **ONLINE**.                                                                                                                                                                                                                                                                                                           |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members_links    | No              | Array           | Provides links to the previous or next page during pagination query, respectively.                                                                                                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter exists only in the response body of pagination query. For details, see :ref:`Table 5 <elb_zq_hd_0006__en-us_topic_0000001129421772_table168848562488>`.                                                                                                                                                                     |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. table:: **Table 2** **members_links** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                   |
   +=======================+=======================+===============================================================================================+
   | href                  | String                | Provides links to the previous or next page during pagination query, respectively.            |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | rel                   | String                | Specifies the prompt of the previous or next page. The value can be **next** or **previous**. |
   |                       |                       |                                                                                               |
   |                       |                       | -  **next**: indicates the URL of the next page.                                              |
   |                       |                       | -  **previous**: indicates the URL of the previous page.                                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 3** Response parameters

   +-----------+-------+--------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type  | Description                                                                                                                    |
   +===========+=======+================================================================================================================================+
   | members   | Array | Lists the backend servers. For details, see :ref:`Table 4 <elb_zq_hd_0006__en-us_topic_0000001129421772_table19836165644814>`. |
   +-----------+-------+--------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0006__en-us_topic_0000001129421772_table19836165644814:

.. table:: **Table 4** **members** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                             |
   +=======================+=======================+=========================================================================================================================================================================+
   | id                    | String                | Specifies the backend server ID.                                                                                                                                        |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | .. note::                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       |    The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the backend server is used.                                                                                                       |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the backend server name.                                                                                                                                      |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                | Specifies the private IP address of the backend server. This IP address must be in the subnet specified by **subnet_id**.                                               |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | This parameter can be set only to the IP address of the primary NIC, for example, 192.168.3.11.                                                                         |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                                          |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server. The port number ranges from 1 to 65535.                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id             | String                | Specifies the ID of the subnet where the backend server works. The private IP address of the backend server is in this subnet.                                          |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | IPv6 subnets are not supported.                                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server.                                                                                                              |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                     |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | -  **true**: Enabled                                                                                                                                                    |
   |                       |                       | -  **false**: Disabled                                                                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer               | Specifies the backend server weight. The value ranges from **0** to **100**.                                                                                            |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | If the value is **0**, the backend server will not accept new requests. The default value is **1**.                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the health check result of the backend server. The value can be one of the following:                                                                         |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                                  |
   |                       |                       | -  **NO_MONITOR**: No health check is performed on the backend server.                                                                                                  |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                               |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | device_id             | String                | Specifies the ID of the cloud server used as the backend server. If the cloud server does not exist, this parameter is an empty string.                                 |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | device_owner          | String                | Specifies the resource ID and AZ ID of the cloud server used as the backend server, for example, **compute:az2.dc2**.                                                   |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | If no corresponding ECS is available, the value is an empty string.                                                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id       | String                | Specifies the backend server ID.                                                                                                                                        |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members_links         | Array                 | Provides links to the previous or next page during pagination query, respectively.                                                                                      |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | This parameter exists only in the response body of pagination query. For details, see :ref:`Table 5 <elb_zq_hd_0006__en-us_topic_0000001129421772_table168848562488>`.  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pool_id               | String                | Specifies the backend server ID.                                                                                                                                        |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0006__en-us_topic_0000001129421772_table168848562488:

.. table:: **Table 5** **members_links** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                   |
   +=======================+=======================+===============================================================================================+
   | href                  | String                | Provides links to the previous or next page during pagination query, respectively.            |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | rel                   | String                | Specifies the prompt of the previous or next page. The value can be **next** or **previous**. |
   |                       |                       |                                                                                               |
   |                       |                       | -  **next**: indicates the URL of the next page.                                              |
   |                       |                       | -  **previous**: indicates the URL of the previous page.                                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request 1: Querying all backend servers

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/members

-  Example request 2: Displaying two backend servers on each page and filtering out backend servers whose health check result is **OFFLINE**

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/members?operating_status=OFFLINE&limit=2

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "members": [
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.11",
                  "protocol_port": 880,
                  "id": "50bd4ae0-fdf4-4540-b94a-04ce6241751e",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              },
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.12",
                  "protocol_port": 880,
                  "id": "fa2045e3-b296-406b-ad12-1611dce44be6",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              }
          ]
      }

-  Example response 2

   .. code-block::

      {
          "members_links": [
              {
                  "href": "https://network.localdomain.com:8020/v2.0/lbaas/members?pool_id=b299051c-a154-4bd6-b630-215151593306&marker=50bd4ae0-fdf4-4540-b94a-04ce6241751e&page_reverse=True",
                  "rel": "previous"
              }
          ],
          "members": [
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.11",
                  "protocol_port": 880,
                  "id": "50bd4ae0-fdf4-4540-b94a-04ce6241751e",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              },
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.12",
                  "protocol_port": 880,
                  "id": "fa2045e3-b296-406b-ad12-1611dce44be6",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              }
          ]
      }

Return Codes
------------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
